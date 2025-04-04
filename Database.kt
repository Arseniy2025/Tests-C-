package com.example.lib125.Database

import android.content.Context
import androidx.compose.runtime.Composable
import androidx.compose.runtime.remember
import androidx.compose.ui.Modifier

import androidx.compose.ui.unit.dp

import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.material3.TextField
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.setValue
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.input.KeyboardType
import androidx.room.Dao
import androidx.room.Database
import androidx.room.Entity
import androidx.room.Insert
import androidx.room.PrimaryKey
import androidx.room.Query
import androidx.room.Room
import androidx.room.RoomDatabase
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.launch


@Entity
data class Purchase(
    @PrimaryKey(autoGenerate = true) val id: Int = 0,
    val productName: String,
    val price: Double
)

@Dao
interface PurchaseDao {
    @Insert
    suspend fun insert(purchase: Purchase)

    @Query("SELECT * FROM purchase ORDER BY id ASC")
    fun getAll(): Flow<List<Purchase>>
}


@Database(
    entities = [Purchase::class],
    version = 1,
    exportSchema = false
)
abstract class AppDatabase : RoomDatabase() {
    abstract fun purchaseDao(): PurchaseDao

    companion object {
        @Volatile
        private var INSTANCE: AppDatabase? = null

        fun getDatabase(context: Context): AppDatabase {
            return INSTANCE ?: synchronized(this) {
                val instance = Room.databaseBuilder(
                    context.applicationContext,
                    AppDatabase::class.java,
                    "purchase_database"
                ).build()
                INSTANCE = instance
                instance
            }
        }
    }
}

@Composable
fun PurchaseApp() {
    val context = LocalContext.current
    val db = remember { AppDatabase.getDatabase(context) }
    val dao = db.purchaseDao()

    var productName by remember { mutableStateOf("") }
    var price by remember { mutableStateOf("") }
    var purchases by remember { mutableStateOf(emptyList<Purchase>()) }

    LaunchedEffect(Unit) {
        dao.getAll().collect { purchasesList ->
            purchases = purchasesList
        }
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp)
    ) {
        TextField(
            value = productName,
            onValueChange = { productName = it },
            label = { Text("Название товара") },
            modifier = Modifier.fillMaxWidth()
        )

        Spacer(modifier = Modifier.height(8.dp))
        TextField(
            value = price,
            onValueChange = { newValue ->
                if (newValue.isEmpty() || newValue.toDoubleOrNull() != null) {
                    price = newValue
                }
            },
            label = { Text("Цена") },
            keyboardOptions = KeyboardOptions.Default.copy(
                keyboardType = KeyboardType.Number
            ),
            modifier = Modifier.fillMaxWidth()
        )

        Spacer(modifier = Modifier.height(16.dp))

        Button(
            onClick = {
                if (productName.isNotBlank() && price.isNotBlank()) {
                    val purchase = Purchase(
                        productName = productName,
                        price = price.toDouble()
                    )

                    CoroutineScope(Dispatchers.IO).launch {
                        dao.insert(purchase)
                    }

                    productName = ""
                    price = ""
                }
            },
            modifier = Modifier.fillMaxWidth()
        ) {
            Text("Добавить покупку")
        }

        Spacer(modifier = Modifier.height(16.dp))

        Column(
            modifier = Modifier
                .fillMaxWidth()
        ) {
            purchases.forEach { purchase ->
                Card(
                    modifier = Modifier
                        .fillMaxWidth()
                        .padding(vertical = 4.dp)
                ) {
                    Column(modifier = Modifier.padding(16.dp)) {
                        Text(
                            text = purchase.productName
                        )
                        Text(
                            text = "Цена: ${purchase.price}"
                        )
                    }
                }
            }
        }
        Card(
            modifier = Modifier
                .fillMaxWidth()
                .padding(top = 8.dp)
        ) {
            Text(
                text = "Общая сумма: ${purchases.sumOf { it.price }}",
                modifier = Modifier.padding(16.dp)
            )
        }
    }
}