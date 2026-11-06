const products = [
    { id:1, name:'Смартфон', price:19990 },
    { id:2, name:'Ноутбук', price:54990 },
    { id:3, name:'Наушники', price:2990 },
    { id:4, name:'Клавиатура', price:3490},
    { id:5, name:'Мышь', price:1590 },
    { id:6, name:'Монитор', price:14990 }
];

const users = {
    admin: { password:'admin123', role:'admin' },
    user:  { password:'user123',  role:'user'  }
};

let currentUser = null;

function logAction(text) {
    const logs = document.getElementById('logs');
    const time = new Date().toLocaleTimeString();
    const entry = document.createElement('div');
    entry.className = 'log-entry';
    entry.textContent = `[${time}] ${text}`;
    logs.prepend(entry);
    console.log(`[LOG] ${text}`);
}

function renderProducts() {
    const grid = document.getElementById('products');
    grid.innerHTML = '';
    products.forEach(p => {
        const card = document.createElement('div');
        card.className = 'card';
        card.innerHTML = `
        <img src="${p.img}" alt="${p.name}">
        <h3>${p.name}</h3>
        <div class="price">${p.price} ₽</div>
        <button onclick="addToCart(${p.id}, '${p.name}')">В корзину</button>
    `;
    grid.appendChild(card);
    });
    logAction('Товары отрисованы (' + products.length + ' шт.)');
}


function addToCart(id, name) {
    if (!currentUser) {
        logAction('Попытка покупки без авторизации: ' + name);
        alert('Войдите, чтобы добавить товар в корзину');
        openLogin();
        return;
    }
    logAction(` ${currentUser} добавил в корзину: ${name} (id=${id})`);
    alert(`"${name}" добавлен в корзину`);
}

function openLogin()  { document.getElementById('loginModal').classList.add('active'); logAction('Открыто окно входа'); }
function closeLogin() { document.getElementById('loginModal').classList.remove('active'); }

function login() {
    const u = document.getElementById('loginInput').value.trim();
    const p = document.getElementById('passInput').value;
    const user = users[u];
    if (!user || user.password !== p) {
        logAction(`Неудачный вход: ${u}`);
        alert('Неверный логин или пароль');
        return;
    }
    currentUser = u;
    updateUserUI();
    closeLogin();
    logAction(`Вход выполнен: ${u} (роль: ${user.role})`);
    document.getElementById('loginInput').value = '';
    document.getElementById('passInput').value = '';
}

function logout() {
    logAction(`Выход: ${currentUser}`);
    currentUser = null;
    document.getElementById('adminPanel').style.display = 'none';
    updateUserUI();
}


function updateUserUI() {
    const label = document.getElementById('userLabel');
    const loginBtn = document.getElementById('loginBtn');
    const logoutBtn = document.getElementById('logoutBtn');
    const adminBtn = document.getElementById('adminBtn');

    if (currentUser) {
        const role = users[currentUser].role;
        label.textContent = `${currentUser} (${role})`;
        loginBtn.style.display = 'none';
        logoutBtn.style.display = 'inline-block';
        adminBtn.style.display = (role === 'admin') ? 'inline-block' : 'none';
    } else {
        label.textContent = 'Гость';
        loginBtn.style.display = 'inline-block';
        logoutBtn.style.display = 'none';
        adminBtn.style.display = 'none';
    }
}

function toggleAdminPanel() {
    if (!currentUser || users[currentUser].role !== 'admin') {
        logAction('Отказ в доступе к админ-панели');
        alert('Доступ запрещён');
        return;
    }
    const p = document.getElementById('adminPanel');
    const visible = p.style.display === 'block';
    p.style.display = visible ? 'none' : 'block';
    logAction(visible ? 'Закрыта админ-панель' : 'Открыта админ-панель');
}


window.addEventListener('DOMContentLoaded', () => {
    renderProducts();
    logAction('Сайт загружен. Пользователь: Гость');
});