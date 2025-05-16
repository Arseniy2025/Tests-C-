package com.example.project

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.launch
import okhttp3.OkHttpClient
import okhttp3.Request

class CountryViewModel : ViewModel() {
    private val _countryData = MutableStateFlow<String?>(null)
    val countryData: StateFlow<String?> = _countryData

    fun fetchCountryData(countryName: String) {
        viewModelScope.launch {
            try {
                val client = OkHttpClient()
                val request = Request.Builder()
                    .url("https://restcountries.com/v3.1/name/$countryName")
                    .build()

                val response = client.newCall(request).execute()
                _countryData.value = response.body?.string() ?: "No data received"
            } catch (e: Exception) {
                _countryData.value = "Error: ${e.message}"
            }
        }
    }
}