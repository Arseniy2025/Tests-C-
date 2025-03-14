package com.example.lib125.RockPaperScissors
import android.annotation.SuppressLint
import android.app.AlertDialog
import android.util.Log
import android.widget.Space
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
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
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.Checkbox
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.material3.TextField
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableFloatStateOf
import androidx.compose.runtime.mutableIntStateOf
import androidx.compose.runtime.mutableStateListOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.unit.dp
import androidx.compose.foundation.layout.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Delete
import androidx.compose.material.icons.filled.Lock
import androidx.compose.material.icons.materialIcon
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.graphics.Brush
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.runtime.*
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import kotlin.random.Random
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp

@Composable
fun NumberGame() {
    var userGuess by remember { mutableStateOf("") }
    var targetNumber by remember { mutableStateOf((1..100).random()) }
    var result by remember { mutableStateOf("") }
    var attempts by remember { mutableStateOf(0) }

    fun checkGuess(guess: Int) {
            attempts++
            when {
                guess == targetNumber -> result = "Поздравляем! Вы угадали число!"
                guess < targetNumber -> result = "Загаданное число больше."
                else -> result = "Загаданное число меньше."
            }
    }

    fun resetGame() {
        targetNumber = (1..100).random()
        userGuess = ""
        result = ""
        attempts = 0
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Text(
            text = "Угадай число от 1 до 100",
            modifier = Modifier.padding(vertical = 16.dp)
        )
        Text(text = "Попыток: $attempts", modifier = Modifier.padding(vertical = 8.dp))
        Text(text = result, modifier = Modifier.padding(vertical = 8.dp))

        TextField(
            value = userGuess,
            onValueChange = { userGuess = it },
            label = { Text("Ваше число") },
            keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
            modifier = Modifier.padding(8.dp)
        )

        Button(
            onClick = {
                val guess = userGuess.toIntOrNull()
                if (guess != null) {
                    checkGuess(guess)
                } else {
                    result = "Пожалуйста, введите корректное число."
                }
            },
            modifier = Modifier.padding(8.dp)
        ) {
            Text(text = "Проверить")
        }

        Button(
            onClick = { resetGame() },
            modifier = Modifier.padding(8.dp)
        ) {
            Text(text = "Новая игра")
        }
    }
}








