package com.example.myproject

import CountriesSearchScreen
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.material3.MaterialTheme
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.getValue
import androidx.compose.runtime.setValue

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            MaterialTheme {
                var showStartScreen by remember { mutableStateOf(true) }

                if (showStartScreen) {
                    StartScreen(onButtonClick = { showStartScreen = false })
                } else {
                    CountriesSearchScreen()
                }
            }
        }
    }
}