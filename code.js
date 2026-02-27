// Задание 1
class User {
    constructor(name) {
        this.name = name;
    }
    
    sayHi() {
        console.log(`Привет, меня зовут ${this.name}`);
    }
}

const user1 = new User("Анна");
const user2 = new User("Иван");

user1.sayHi();
user2.sayHi();


// Задание 2
class Counter {
    constructor() {
        this.count = 0;
    }
    
    increase() {
        this.count++;
    }
    
    decrease() {
        this.count--;
    }
    
    getCurrent() {
        return this.count;
    }
}

const counter = new Counter();
counter.increase();
counter.increase();
counter.increase();
counter.decrease();
console.log(counter.getCurrent());


// Задание 3
class Animal {
    constructor(name) {
        this.name = name;
    }
    
    speak() {
        console.log("Животное издает звук");
    }
}

class Dog extends Animal {
    speak() {
        console.log("Гав!");
    }
}
const dog = new Dog("Шарик");
dog.speak();


// Задание 4
class Rectangle {
    constructor(width, height) {
        this.width = width;
        this.height = height;
    }
    
    get area() {
        return this.width * this.height;
    }
    
    get perimeter() {
        return 2 * (this.width + this.height);
    }
}

const rect = new Rectangle(5, 3);
console.log(rect.area);      
console.log(rect.perimeter); 


// Задание 5
class MathHelper {
    static add(a, b) {
        return a + b;
    }
    
    static multiply(a, b) {
        return a * b;
    }
}
console.log(MathHelper.add(2, 5));  
console.log(MathHelper.multiply(3, 4)); 


// Задание 6
class Wallet {
    #balance;
    
    constructor(initialBalance) {
        this.#balance = initialBalance;
    }
    
    deposit(amount) {
        this.#balance += amount;
    }
    
    getBalance() {
        return this.#balance;
    }
}

const wallet = new Wallet(100);
console.log(wallet.#balance);

// Задание 7
class Product {
    constructor(initialPrice) {
        this.price = Math.max(0, initialPrice);
    }
    
    set price(newPrice) {
        this.price = Math.max(0, newPrice);
    }
    
    get price() {
        return this.price;
    }
}

const product = new Product(100);
console.log(product.price); 
product.price = -50;
console.log(product.price); 
product.price = 200;
console.log(product.price); 

// Задание 8
class Book {
    constructor(title) {
        this.title = title;
        this.isRead = false;
    }
    
    markAsRead() {
        this.isRead = true;
    }
}

const book1 = new Book("Преступление и наказание");
const book2 = new Book("Гарри Поттер и орден феникса");
const book3 = new Book("Путешествие к центру земли");

book2.markAsRead();

console.log(`${book1.title}: ${book1.isRead ? 'прочитана' : 'не прочитана'}`); 
console.log(`${book2.title}: ${book2.isRead ? 'прочитана' : 'не прочитана'}`); 
console.log(`${book3.title}: ${book3.isRead ? 'прочитана' : 'не прочитана'}`); 

// Задание 9
class Item {
    constructor(name, price) {
        this.name = name;
        this.price = price;
    }
}

class Order {
    constructor() {
        this.items = [];
    }
    
    addItem(item) {
        this.items.push(item);
    }
    
    getTotal() {
        return this.items.reduce((total, item) => total + item.price, 0);
    }
}

const order = new Order();
order.addItem(new Item("Книга", 399));
order.addItem(new Item("Ручка", 32));
order.addItem(new Item("Тетрадь", 99));
console.log(order.getTotal());

// Задание 10
class TodoList {
    #tasks = [];
    
    addTask(text) {
        this.#tasks.push(text);
    }
    
    removeTask(index) {
        if (index >= 0 && index < this.#tasks.length) {
            this.#tasks.splice(index, 1);
        }
    }
    
    listTasks() {
        console.log("Список задач:");
        this.#tasks.forEach((task, index) => {
            console.log(`${index + 1}. ${task}`);
        });
    }
}

const todo = new TodoList();
todo.addTask("Купить продукты");
todo.addTask("Сделать домашнее задание");
todo.addTask("Позвонить другу");

console.log("После добавления:");
todo.listTasks();

todo.removeTask(1); 

console.log("\nПосле удаления:");
todo.listTasks();








