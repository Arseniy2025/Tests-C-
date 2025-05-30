package com.example.project

import android.util.Log
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.google.gson.Gson
import com.google.gson.JsonSyntaxException
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.launch
import okhttp3.OkHttpClient
import okhttp3.Request
import java.io.IOException
import java.text.DecimalFormat

enum class SearchType(val urlTemplate: String) {
    BY_NAME("https://restcountries.com/v3.1/name/%s"),
    BY_FULL_NAME("https://restcountries.com/v3.1/name/%s?fullText=true"),
    BY_CURRENCY("https://restcountries.com/v3.1/currency/%s"),
    BY_CAPITAL("https://restcountries.com/v3.1/capital/%s"),
    BY_REGION("https://restcountries.com/v3.1/region/%s"),
    BY_SUBREGION("https://restcountries.com/v3.1/subregion/%s")
}

class CountryViewModel : ViewModel() {
    private val client = OkHttpClient()
    private val gson = Gson()

    private val _countries = MutableStateFlow<List<Country>?>(null)
    val countries: StateFlow<List<Country>?> = _countries

    private val _isLoading = MutableStateFlow(false)
    val isLoading: StateFlow<Boolean> = _isLoading

    private val _error = MutableStateFlow<String?>(null)
    val error: StateFlow<String?> = _error

    fun fetchCountryData(searchType: SearchType, query: String) {
        viewModelScope.launch {
            _isLoading.value = true
            try {
                val url = String.format(searchType.urlTemplate, query)
                val request = Request.Builder().url(url).build()


                val response = client.newCall(request).execute()


            } catch (e: Exception) {
                _error.value = "Ошибка: ${e.message}"
            } finally {
                _isLoading.value = false
            }
        }
    }
}

data class Country(
    val name: Name,
    val capital: List<String>?,
    val region: String,
    val subregion: String?,
    val population: Long,
    val flags: Flags,
    val currencies: Map<String, Currency>?,
    val languages: Map<String, String>?
)

data class Name(
    val common: String,
    val official: String
)

data class Flags(
    val png: String,
    val svg: String
)

data class Currency(
    val name: String,
    val symbol: String?
)

fun Long.formatPopulation(): String {
    return DecimalFormat("#,###").format(this)
}
