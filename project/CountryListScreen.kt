package com.example.project.screens

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import coil.compose.rememberImagePainter
import com.example.project.Country
import com.example.project.CountryViewModel
import com.example.project.SearchType
import com.example.project.formatPopulation

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun CountryListScreen(
    onBackClick: () -> Unit,
    viewModel: CountryViewModel
) {
    var query by remember { mutableStateOf("") }
    val searchTypes = listOf(
        "По названию" to SearchType.BY_NAME,
        "Полное название" to SearchType.BY_FULL_NAME,
        "По валюте" to SearchType.BY_CURRENCY,
        "По столице" to SearchType.BY_CAPITAL,
        "По региону" to SearchType.BY_REGION,
        "По субрегиону" to SearchType.BY_SUBREGION
    )
    var selectedTypeIndex by remember { mutableStateOf(0) }
    val selectedSearchType = searchTypes[selectedTypeIndex].second

    val countries by viewModel.countries.collectAsState()
    val isLoading by viewModel.isLoading.collectAsState()
    val error by viewModel.error.collectAsState()

    Scaffold(
        topBar = {
            TopAppBar(
                title = { Text("Список стран") },
                navigationIcon = {
                    TextButton(onClick = onBackClick) {
                        Text("Назад")
                    }
                }
            )
        }
    ) { paddingValues ->
        Column(
            modifier = Modifier
                .fillMaxSize()
                .padding(paddingValues)
                .padding(16.dp),
            verticalArrangement = Arrangement.Top
        ) {
            // Выбор типа поиска
            var expanded by remember { mutableStateOf(false) }
            Box {
                OutlinedButton(
                    onClick = { expanded = true },
                    modifier = Modifier.fillMaxWidth()
                ) {
                    Text(text = "Тип поиска: ${searchTypes[selectedTypeIndex].first}")
                }
                DropdownMenu(
                    expanded = expanded,
                    onDismissRequest = { expanded = false }
                ) {
                    searchTypes.forEachIndexed { index, pair ->
                        DropdownMenuItem(
                            text = { Text(pair.first) },
                            onClick = {
                                selectedTypeIndex = index
                                expanded = false
                            }
                        )
                    }
                }
            }

            Spacer(modifier = Modifier.height(8.dp))

            // Поле ввода запроса
            OutlinedTextField(
                value = query,
                onValueChange = { query = it },
                label = { Text("Введите значение") },
                modifier = Modifier.fillMaxWidth()
            )

            Spacer(modifier = Modifier.height(8.dp))

            
            Button(
                onClick = {
                    if (query.isNotBlank()) {
                        viewModel.fetchCountryData(selectedSearchType, query)
                    }
                },
                modifier = Modifier.align(Alignment.End),
                enabled = !isLoading
            ) {
                if (isLoading) {
                    CircularProgressIndicator(
                        modifier = Modifier.size(20.dp),
                        color = MaterialTheme.colorScheme.onPrimary,
                        strokeWidth = 2.dp
                    )
                } else {
                    Text("Поиск")
                }
            }

            Spacer(modifier = Modifier.height(16.dp))

            // Отображение результатов
            when {
                isLoading -> {
                    Box(
                        modifier = Modifier.fillMaxSize(),
                        contentAlignment = Alignment.Center
                    ) {
                        CircularProgressIndicator()
                    }
                }
                error != null -> {
                    Box(
                        modifier = Modifier.fillMaxSize(),
                        contentAlignment = Alignment.Center
                    ) {
                        Text(
                            text = error!!,
                            color = MaterialTheme.colorScheme.error,
                            modifier = Modifier.padding(8.dp)
                        )
                    }
                }
                !countries.isNullOrEmpty() -> {
                    LazyColumn(
                        modifier = Modifier.fillMaxSize(),
                        verticalArrangement = Arrangement.spacedBy(8.dp)
                    ) {
                        items(countries!!) { country ->
                            CountryItem(country = country)
                        }
                    }
                }
                else -> {
                    Box(
                        modifier = Modifier.fillMaxSize(),
                        contentAlignment = Alignment.Center
                    ) {
                        Text(
                            text = "Введите запрос для поиска",
                            color = MaterialTheme.colorScheme.onSurface.copy(alpha = 0.6f)
                        )
                    }
                }
            }
        }
    }
}

@Composable
fun CountryItem(country: Country) {
    Card(
        modifier = Modifier
            .fillMaxWidth()
            .padding(horizontal = 4.dp),
        elevation = CardDefaults.cardElevation(defaultElevation = 4.dp),
        colors = CardDefaults.cardColors(
            containerColor = MaterialTheme.colorScheme.surfaceVariant
        )
    ) {
        Column(modifier = Modifier.padding(16.dp)) {
            // Заголовок с флагом и названием
            Row(verticalAlignment = Alignment.CenterVertically) {
                Image(
                    painter = rememberImagePainter(country.flags.png),
                    contentDescription = "Флаг ${country.name.common}",
                    modifier = Modifier
                        .size(48.dp)
                        .padding(end = 16.dp),
                    contentScale = ContentScale.Fit
                )
                Column {
                    Text(
                        text = country.name.common,
                        style = MaterialTheme.typography.titleLarge,
                        fontWeight = FontWeight.Bold
                    )
                    Text(
                        text = country.name.official,
                        style = MaterialTheme.typography.bodyMedium,
                        color = MaterialTheme.colorScheme.onSurface.copy(alpha = 0.7f)
                    )
                }
            }

            Spacer(modifier = Modifier.height(12.dp))

            // Информация о стране
            InfoRow("Регион", "${country.region} ${country.subregion ?: ""}")

            country.capital?.firstOrNull()?.let { capital ->
                InfoRow("Столица", capital)
            }

            InfoRow("Население", country.population.formatPopulation())

            country.currencies?.values?.firstOrNull()?.let { currency ->
                InfoRow(
                    label = "Валюта",
                    value = "${currency.name} (${currency.symbol ?: "нет символа"})"
                )
            }
        }
    }
}

@Composable
fun InfoRow(label: String, value: String) {
    Row(
        modifier = Modifier.padding(vertical = 4.dp),
        verticalAlignment = Alignment.CenterVertically
    ) {
        Text(
            text = "$label: ",
            style = MaterialTheme.typography.bodyMedium,
            fontWeight = FontWeight.Bold
        )
        Text(
            text = value,
            style = MaterialTheme.typography.bodyMedium
        )
    }
}
