import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import kotlinx.coroutines.launch
import okhttp3.OkHttpClient
import okhttp3.Request
import com.google.gson.Gson
import com.google.gson.reflect.TypeToken

// Модели данных
data class Country(
    val name: Name?
)

data class Name(
    val common: String?
)

sealed class SearchMode(val label: String) {
    object Name : SearchMode("По названию")
    object FullName : SearchMode("Полное название")
    object Currency : SearchMode("Валюта")
    object Capital : SearchMode("Столица")
    object Region : SearchMode("Регион")
    object Subregion : SearchMode("Субрегион")
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun CountriesSearchScreen() {
    val client = remember { OkHttpClient() }
    val gson = remember { Gson() }

    var query by remember { mutableStateOf("") }
    var countries by remember { mutableStateOf<List<Country>?>(null) }
    var isLoading by remember { mutableStateOf(false) }
    var errorMessage by remember { mutableStateOf<String?>(null) }

    var selectedMode by remember { mutableStateOf<SearchMode>(SearchMode.Name) }
    var expanded by remember { mutableStateOf(false) }

    val coroutineScope = rememberCoroutineScope()

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp)
    ) {
        // TopAppBar с выбором режима поиска
        TopAppBar(
            title = { Text("Информация о странах") },
            actions = {
                Box {
                    TextButton(onClick = { expanded = true }) {
                        Text(selectedMode.label)
                    }
                    DropdownMenu(
                        expanded = expanded,
                        onDismissRequest = { expanded = false }
                    ) {
                        listOf(
                            SearchMode.Name,
                            SearchMode.FullName,
                            SearchMode.Currency,
                            SearchMode.Capital,
                            SearchMode.Region,
                            SearchMode.Subregion
                        ).forEach { mode ->
                            DropdownMenuItem(
                                text = { Text(mode.label) },
                                onClick = {
                                    selectedMode = mode
                                    expanded = false
                                }
                            )
                        }
                    }
                }
            }
        )

        Spacer(modifier = Modifier.height(8.dp))

        // Поле ввода
        TextField(
            value = query,
            onValueChange = { query = it },
            label = { Text("Введите значение") },
            modifier = Modifier.fillMaxWidth()
        )

        Spacer(modifier = Modifier.height(8.dp))

        // Кнопка поиска
        Button(
            onClick = {
                if (query.isNotBlank()) {
                    coroutineScope.launch {
                        isLoading = true
                        errorMessage = null
                        countries = null
                        try {
                            val url = buildUrl(selectedMode, query)
                            val request = Request.Builder()
                                .url(url)
                                .build()

                            val response = client.newCall(request).execute()

                            if (!response.isSuccessful) {
                                throw Exception("Ошибка сети: ${response.code}")
                            }

                            val responseBody = response.body?.string()

                            if (responseBody.isNullOrBlank()) {
                                countries = emptyList()
                            } else {
                                val listType = object : TypeToken<List<Country>>() {}.type
                                val result: List<Country> = gson.fromJson(responseBody, listType)
                                countries = result
                            }
                        } catch (e: Exception) {
                            errorMessage = e.localizedMessage ?: "Ошибка при запросе"
                        } finally {
                            isLoading = false
                        }
                    }
                }
            },
            modifier = Modifier.fillMaxWidth()
        ) {
            Text("Искать")
        }

        Spacer(modifier = Modifier.height(16.dp))

        // Отображение результатов, ошибок или загрузки
        when {
            isLoading -> {
                Box(
                    modifier = Modifier
                        .fillMaxWidth()
                        .height(50.dp),
                    contentAlignment = Alignment.Center
                ) {
                    CircularProgressIndicator()
                }
            }
            errorMessage != null -> {
                Text(
                    text = "Ошибка: $errorMessage",
                    color = MaterialTheme.colorScheme.error,
                    style = MaterialTheme.typography.bodyMedium,
                    modifier = Modifier.padding(8.dp)
                )
            }
            countries != null -> {
                if (countries!!.isEmpty()) {
                    Text(
                        text = "Страны не найдены",
                        style = MaterialTheme.typography.bodyMedium,
                        modifier = Modifier.padding(8.dp)
                    )
                } else {
                    LazyColumn {
                        items(countries!!) { country ->
                            Text(
                                text = country.name?.common ?: "Нет названия",
                                fontSize = 18.sp,
                                modifier = Modifier
                                    .fillMaxWidth()
                                    .padding(8.dp)
                            )
                        }
                    }
                }
            }
            else -> {
                // Можно оставить пустым или показывать сообщение
                Box(
                    modifier = Modifier
                        .fillMaxWidth()
                        .height(50.dp),
                    contentAlignment = Alignment.Center
                ) {
                    Text("Введите запрос и нажмите 'Искать'")
                }
            }
        }
    }
}

// Построение URL в зависимости от режима поиска
fun buildUrl(mode: SearchMode, query: String): String {
    val baseUrl = "https://restcountries.com/v3.1"
    val urlTemplates = mapOf<SearchMode, String>(
        SearchMode.Name to "$baseUrl/name/$query",
        SearchMode.FullName to "$baseUrl/name/$query?fullText=true",
        SearchMode.Currency to "$baseUrl/currency/$query",
        SearchMode.Capital to "$baseUrl/capital/$query",
        SearchMode.Region to "$baseUrl/region/$query",
        SearchMode.Subregion to "$baseUrl/subregion/$query"
    )

    return urlTemplates[mode] ?: "$baseUrl/name/$query"
}