package com.example.project
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import okhttp3.OkHttpClient
import okhttp3.Request
import okhttp3.Response
import java.io.IOException
import com.example.project.ui.theme.ProjectTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            ProjectTheme {
                fetchCountryByName("Russia")

                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    MainScreen()
                }
            }
        }
    }
}

@Composable
fun MainScreen() {
    val navController = rememberNavController()

    NavHost(navController, startDestination = "start") {
        composable("start") {
            StartScreen {
                navController.navigate("country_list")
            }
        }
        composable("country_list") {
            CountryListScreen {
                navController.popBackStack()
            }
        }
    }
}

@Composable
fun StartScreen(onButtonClick: () -> Unit) {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(24.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = "Моё приложение",
            fontSize = 24.sp,
            fontWeight = FontWeight.Bold,
            modifier = Modifier.padding(bottom = 16.dp)
        )

        Button(
            onClick = onButtonClick,
            modifier = Modifier.padding(top = 32.dp)
        ) {
            Text("Начать")
        }
    }
}
@Preview(showBackground = true)
@Composable
fun StartScreenPrew() {
    ProjectTheme {
        StartScreen {}
    }
}

fun fetchCountryByName(countryName: String) {
    val url = "https://restcountries.com/v3.1/name/$countryName"

    val client = OkHttpClient()

    val request = Request.Builder()
        .url(url)
        .build()

    client.newCall(request).enqueue(object : okhttp3.Callback {
        override fun onFailure(call: okhttp3.Call, e: IOException) {

            println("Ошибка при выполнении запроса: ${e.message}")
        }

        override fun onResponse(call: okhttp3.Call, response: Response) {
            response.use { resp ->
                if (!resp.isSuccessful) {
                    println("Не удалось получить данные: ${resp.code}")
                } else {
                    val responseData = resp.body?.string()
                    println("Ответ API:\n$responseData")
                }
            }
        }
    })
}




