package com.example.dz.DZ3

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
import androidx.compose.foundation.shape.RoundedCornerShape
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

data class Task(
    val title: String,
    val description: String,
    var isCompleted: Boolean = false,
    var priority: Int = 0,
)

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun TaskManager() {
    val tasks = remember { mutableStateListOf<Task>() }
    val archiveTasks = remember { mutableStateListOf<Task>() }

    var showDialog by remember { mutableStateOf(false) }
    var title by remember { mutableStateOf("") }
    var description by remember { mutableStateOf("") }

    var showArchiveTasks by remember { mutableStateOf(false) }

    Scaffold(
        floatingActionButton = {
            FloatingActionButton(onClick = {
                showDialog = true
            }) { Text("+") }
        },
        topBar = {
            CenterAlignedTopAppBar(
                title = { Text("Task manager") },
                colors = TopAppBarDefaults.centerAlignedTopAppBarColors(
                    containerColor = Color(0xFFF13434),
                    titleContentColor = Color.Black
                )
            )
        }
    ) { padding ->
        Column(
            modifier = Modifier.padding(padding).fillMaxSize(),
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
            Row(modifier = Modifier.padding(8.dp).fillMaxWidth()) {
                OutlinedButton(
                    onClick = { showArchiveTasks = false },
                    enabled = showArchiveTasks,
                    shape = RoundedCornerShape(4.dp)
                ) {
                    Text("Активные задачи")
                }

                Spacer(modifier = Modifier.width(24.dp))

                OutlinedButton(
                    onClick = { showArchiveTasks = true },
                    enabled = !showArchiveTasks,
                    shape = RoundedCornerShape(4.dp)
                ) {
                    Row {
                        Text("Архивные задачи")
                        Icon(Icons.Default.Lock, contentDescription = null)
                    }
                }
            }

            Spacer(modifier = Modifier.height(8.dp))

            if (!showArchiveTasks) {

                val sortedTasks = tasks.sortedByDescending { it.priority }
                sortedTasks.forEach { task ->
                    TaskItem(task) {
                        tasks.remove(task)
                        archiveTasks.add(task)
                    }
                }
            } else {
                val sortedArchiveTasks = archiveTasks.sortedByDescending { it.priority }
                sortedArchiveTasks.forEach { task ->
                    TaskItem(task) {
                        archiveTasks.remove(task)
                    }
                }
            }
        }

        if (showDialog) {
            var priority: Int = 0
            AlertDialog(
                onDismissRequest = { showDialog = false },
                title = { Text("Добавить новую задачу") },
                text = {
                    Column {
                        TextField(
                            value = title,
                            onValueChange = { title = it },
                            label = { Text("Название задачи") }
                        )
                        TextField(
                            value = description,
                            onValueChange = { description = it },
                            label = { Text("Описание задачи") }
                        )

                        Row(modifier = Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.Center) {
                            Column(horizontalAlignment = Alignment.CenterHorizontally) {
                                var isChecked by remember { mutableStateOf(true) }
                                Checkbox(
                                    checked = isChecked,
                                    onCheckedChange = {
                                        isChecked = it
                                        priority = 0
                                    }
                                )
                                Text("0")
                            }
                            Column(horizontalAlignment = Alignment.CenterHorizontally) {
                                var isChecked by remember { mutableStateOf(false) }
                                Checkbox(
                                    checked = isChecked,
                                    onCheckedChange = {
                                        isChecked = it
                                        priority = 1
                                    }
                                )
                                Text("1")
                            }
                            Column(horizontalAlignment = Alignment.CenterHorizontally) {
                                var isChecked by remember { mutableStateOf(false) }
                                Checkbox(
                                    checked = isChecked,
                                    onCheckedChange = {
                                        isChecked = it
                                        priority = 2
                                    }
                                )
                                Text("2")
                            }
                        }
                    }
                },
                confirmButton = {
                    Button(onClick = {
                        if (title.isNotEmpty() && description.isNotEmpty()) {
                            tasks.add(Task(title, description, false, priority))
                            title = ""
                            description = ""
                            showDialog = false
                        }
                    }) {
                        Text("Добавить")
                    }
                },
                dismissButton = {
                    Button(onClick = { showDialog = false }) {
                        Text("Отмена")
                    }
                }
            )
        }
    }
}

@Composable
fun TaskItem(task: Task, onDelete: () -> Unit){
    var isChecked by remember { mutableStateOf(task.isCompleted) }

    val color: Color = when(task.priority){
        0 -> Color.Green
        1 -> Color.Yellow
        2 -> Color.Red
        else -> {Color.Cyan}
    }

    Card(
        colors = CardColors(
            containerColor = color,
            contentColor = Color.Black,
            disabledContainerColor = Color.Gray,
            disabledContentColor = Color.Black,
        ),
        modifier = Modifier.padding(8.dp),
    )
    {
        Row(
            modifier = Modifier.fillMaxWidth().padding(vertical = 8.dp),
            verticalAlignment = Alignment.CenterVertically
        ){
            Checkbox(
                checked = isChecked,
                onCheckedChange = {
                    isChecked = it
                    task.isCompleted = it
                }
            )
            Spacer(modifier = Modifier.height(8.dp))
            Column(
                modifier = Modifier.weight(1f)
            ){
                Text(task.title)
                Text(task.description)
            }

            IconButton(onClick = {
                onDelete();
            }, modifier = Modifier) { Icon(Icons.Default.Delete, contentDescription = null) }
        }
    }
}