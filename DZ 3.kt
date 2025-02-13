package com.example.dz.DZ2

import android.os.Bundle
import android.util.Log
import android.widget.Space
import android.widget.Toast
import android.widget.Toast.LENGTH_SHORT
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.defaultMinSize
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.itemsIndexed
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.material3.TextField
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableFloatStateOf
import androidx.compose.runtime.mutableIntStateOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp

//Задание 1
@Composable
fun Home1() {
    val participant: MutableList<String> = mutableListOf("Smith", "Johnson", "Williams", "Brown", "Jones")
    DrawParticipant(participant)
}

@Composable
fun DrawParticipant(list: MutableList<String>){
    LazyColumn (modifier = Modifier.fillMaxSize(), horizontalAlignment = Alignment.CenterHorizontally, verticalArrangement = Arrangement.Center){
        items(list.size) { index ->
            Card(modifier = Modifier.defaultMinSize(100.dp,50.dp).width(150.dp)) {
                Row(modifier = Modifier.fillMaxSize(), verticalAlignment = Alignment.CenterVertically, horizontalArrangement = Arrangement.Center) {
                    Text("${index + 1}")
                    Spacer(modifier = Modifier.width((8.dp)))
                    Text(list[index])
                }
            }
        }
    }
}

//Задание 2
fun EvenNumbers(count: Int): List<Int> {
    return List(count) { it * 2 }
}

@Composable
fun Home2() {
    EvenNumbersLazyColumn()
    //EvenNumbersColumn()
}

@Composable
fun EvenNumbersColumn() {
    val evenNumbers = EvenNumbers(100)
    Column(
        modifier = Modifier.fillMaxSize(),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        evenNumbers.forEach { number ->
            Button(onClick = { }) {
                Text(text = number.toString())
            }
        }
    }
}

@Composable
fun EvenNumbersLazyColumn() {
    val evenNumbers = EvenNumbers(100)
    LazyColumn(
        modifier = Modifier.fillMaxSize(),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        items(evenNumbers.size) { index ->
            Button(onClick = {}) {
                Text(text = evenNumbers[index].toString())
            }
        }
    }
}



