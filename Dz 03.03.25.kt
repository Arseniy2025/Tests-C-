//Задание 1 
fun main() {
    println("Введите символ:")
    val input = readLine()
    if (input == null || input[0] !in 'A'..'Z') {
        println("Это не латинская прописная буква.")
        return
    }

    val char = input[0] 

    if (char == 'L' || char == 'M' || char == 'K' || char == 'D') {
        println("Это согласные буквы")
    } else {
        println("Возможно, это гласные буквы")
    }
}
//Задание 2
fun main() {
    var str1 = "Первая строка"
    val str2 = " и вторая строка"

    str1 += str2
    println(str1)
}
//Задание 3
fun main() {
    val str = "Пример строки"
    println(str.reversed())
}
