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
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material3.Button
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
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp

@Composable
fun Home() {
    var inputString by remember { mutableStateOf("") }
    var modString by remember { mutableStateOf("") }
    var letterCount by remember { mutableStateOf(0) }

    Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
        Column(
            modifier = Modifier
                .padding(innerPadding)
                .fillMaxSize(),
            horizontalAlignment = Alignment.CenterHorizontally,
            verticalArrangement = Arrangement.Center
        ) {
            TextField(
                value = inputString,
                onValueChange = {
                    inputString = it
                    modString = replaced(it)
                    letterCount = it.count { char -> char.isLetter() }
                },
            )

            Spacer(modifier = Modifier.height(16.dp))

            Text("Измененная строка: $modString")
            Text("Количество букв: $letterCount")
        }
    }
}

fun replaced(input: String): String {
    val result = StringBuilder()
    for (char in input) {
        if (char.isLetter()) {
            result.append(' ')
        } else {
            result.append(char)
        }
    }
    return result.toString()
}