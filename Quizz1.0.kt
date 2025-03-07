package com.example.lib125
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
import androidx.compose.ui.unit.dp

@Composable
fun QuizApp() {
    var Selection by remember { mutableStateOf(true) }
    var difficulty by remember { mutableStateOf("Легкий") }
    var questions by remember { mutableStateOf(emptyList<Question>()) }
    var currentQuestion by remember { mutableIntStateOf(0) }
    var selectedAnswer by remember { mutableStateOf("") }
    var score by remember { mutableIntStateOf(0) }
    var quizFinished by remember { mutableStateOf(false) }

    if (Selection) {
        Column(
            modifier = Modifier.fillMaxSize().padding(16.dp),
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
            Text(text = "Выберите сложность:")
            Spacer(modifier = Modifier.height(16.dp))
            Button(onClick = {
                difficulty = "Легкий"
                questions = listOf(
                    Question("Какая страна самая крупная?", listOf("Китай", "Россия", "США"), "Россия"),
                    Question("Какой сейчас год?", listOf("2025", "2000", "2008"), "2025")
                )
                Selection = false
            }) {
                Text(text = "Легкий")
            }
            Button(onClick = {
                difficulty = "Средний"
                questions = listOf(
                    Question("Сколько планет в Солнечной системе?", listOf("8", "9", "10"), "8"),
                    Question("Кто написал 'Войну и мир'?", listOf("Достоевский", "Толстой", "Чехов"), "Толстой"),
                    Question("Что можно видеть с закрытыми глазами?", listOf("Темнота", "Сны", "Ничего"), "Сны"),
                    Question("Сколько будет 2+2*2??", listOf("7", "5", "6"), "6")

                )
                Selection = false
            }) {
                Text(text = "Средний")
            }
            Button(onClick = {
                difficulty = "Сложный"
                questions = listOf(
                    Question("Какой элемент имеет атомный номер 79?", listOf("Золото", "Серебро", "Платина"), "Золото"),
                    Question("Кто открыл теорию относительности?", listOf("Ньютон", "Эйнштейн", "Галилей"), "Эйнштейн"),
                    Question("Кого австралийцы называют морской осой?", listOf("Рыба", "Медуза", "Скат"), "Золото"),
                    Question("Чем оканчиваются день и ночь?", listOf("Мягкий знак", "Твёрдый знак", "Новый день"), "Мягкий знак"),
                    Question(" Каких камней в море нет? (В воде)", listOf("Сухих", "Красивых", "Мокрых"), "Сухих"),
                    Question("Что нужно делать, когда видишь зелёного человечка?", listOf("Стоять на месте", "Переходить улицу", "Это пришельцы!!!"), "Переходить улицу")
                )
                Selection = false
            }) {
                Text(text = "Сложный")
            }
        }
    } else {
        Column(
            modifier = Modifier.fillMaxSize().padding(16.dp),
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
            if (!quizFinished) {
                Text(text = "Вопрос: ${questions[currentQuestion].text}")
                Spacer(modifier = Modifier.height(12.dp))
                questions[currentQuestion].options.forEach { option ->
                    Row(
                        modifier = Modifier.fillMaxWidth(),
                        verticalAlignment = Alignment.CenterVertically
                    ) {
                        RadioButton(
                            selected = selectedAnswer == option,
                            onClick = { selectedAnswer = option }
                        )
                        Text(text = option)
                    }
                }
                Spacer(modifier = Modifier.height(16.dp))
                Button(
                    onClick = {
                        if (selectedAnswer == questions[currentQuestion].correctAnswer) {
                            score++
                        }
                        if (currentQuestion < questions.size - 1) {
                            currentQuestion++
                            selectedAnswer = ""
                        } else {
                            quizFinished = true
                        }
                    },
                    enabled = selectedAnswer != ""
                ) {
                    Text(text = if (currentQuestion < questions.size - 1) "Следующий вопрос" else "Закончить")
                }
            } else {
                Text(text = "Ваш результат: $score из ${questions.size}")
                Spacer(modifier = Modifier.height(16.dp))
                Button(onClick = {
                    Selection = true
                    quizFinished = false
                    currentQuestion = 0
                    score = 0
                    selectedAnswer = ""
                }) {
                    Text(text = "Начать заново")
                }
            }
        }
    }
}
data class Question(val text: String, val options: List<String>, val correctAnswer: String)












