interface User {
    id: number;
    name: string;
    email: string;
    registeredAt: Date;
}

const users: User[] = [];

function addUser(name: string, email: string): boolean {
    if (!name || !email) {
        console.log("Имя и email обязательны");
        return false;
    }
    if (users.some(u => u.email === email)) {
        console.log("Пользователь уже существует");
        return false;
    }
    users.push({ id: Date.now(), name, email, registeredAt: new Date() });
    console.log(`Добавлен: ${name}`);
    return true;
}

function findUser(email: string): User | null {
    return users.find(u => u.email === email) ?? null;
}

addUser("Иван", "ivan@mail.ru");
console.log(findUser("ivan@mail.ru"));
console.log(findUser("раыр@mail.ru"));