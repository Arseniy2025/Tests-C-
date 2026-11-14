const products = [
    { id:1, name:'Смартфон',   price:19990 },
    { id:2, name:'Ноутбук',    price:54990 },
    { id:3, name:'Наушники',   price:2990  },
    { id:4, name:'Клавиатура', price:3490  },
    { id:5, name:'Мышь',       price:1590  },
    { id:6, name:'Монитор',    price:14990 }
];


const stock = {
    1: 5,   
    2: 2,   
    3: 12,  
    4: 8,   
    5: 20,  
    6: 3    
};


const pickupPoints = [
    { id:'PVZ-1', name:'ПВЗ Центральный',  x:50, y:50, baseDays:1 },
    { id:'PVZ-2', name:'ПВЗ Северный',     x:30, y:15, baseDays:2 },
    { id:'PVZ-3', name:'ПВЗ Южный',        x:70, y:85, baseDays:2 },
    { id:'PVZ-4', name:'ПВЗ Западный',     x:10, y:60, baseDays:3 },
    { id:'PVZ-5', name:'ПВЗ Восточный',    x:90, y:40, baseDays:3 }
];


const users = {
    admin: { password:'admin123', role:'admin', x:45, y:55 },
    user:  { password:'user123',  role:'user',  x:20, y:80 }
};

let currentUser = null;
let cart = {};        


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
        const left = stock[p.id] ?? 0;
        const card = document.createElement('div');
        card.className = 'card';
        card.innerHTML = `
            <img src="${p.img || ''}" alt="${p.name}">
            <h3>${p.name}</h3>
            <div class="price">${p.price} ₽</div>
            <div class="stock">На складе: ${left} шт.</div>
            <button onclick="addToCart(${p.id})" ${left === 0 ? 'disabled' : ''}>
                ${left === 0 ? 'Нет в наличии' : 'В корзину'}
            </button>
        `;
        grid.appendChild(card);
    });
    logAction('Товары отрисованы (' + products.length + ' шт.)');
}

function addToCart(id) {
    const product = products.find(p => p.id === id);
    if (!currentUser) {
        logAction('Попытка покупки без авторизации: ' + product.name);
        alert('Войдите, чтобы добавить товар в корзину');
        openLogin();
        return;
    }
    const inCart = cart[id] || 0;
    if (inCart + 1 > (stock[id] || 0)) {
        logAction(`Недостаточно на складе: ${product.name}`);
        alert(`На складе только ${stock[id]} шт.`);
        return;
    }
    cart[id] = inCart + 1;
    logAction(`${currentUser} добавил в корзину: ${product.name} (в корзине: ${cart[id]})`);
    renderCart();
}

/* ───────────── КОРЗИНА ───────────── */
function renderCart() {
    const box = document.getElementById('cartBox');
    if (!box) return;
    const items = Object.entries(cart);
    if (!items.length) {
        box.innerHTML = '<p class="empty">Корзина пуста</p>';
        return;
    }
    let total = 0;
    box.innerHTML = items.map(([id, qty]) => {
        const p = products.find(x => x.id === Number(id));
        total += p.price * qty;
        return `<div class="cart-row">
            <span>${p.name}</span>
            <span>${qty} × ${p.price} ₽</span>
            <button onclick="removeFromCart(${id})">−</button>
        </div>`;
    }).join('') + `<div class="cart-total">Итого: ${total} ₽</div>`;
}

function removeFromCart(id) {
    if (!cart[id]) return;
    cart[id]--;
    if (cart[id] <= 0) delete cart[id];
    logAction(`Удалён товар id=${id}`);
    renderCart();
}

/* ───────────── ВХОД/ВЫХОД ───────────── */
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
    cart = {};
    document.getElementById('adminPanel').style.display = 'none';
    document.getElementById('checkoutModal').classList.remove('active');
    updateUserUI();
    renderCart();
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


function distance(a, b) {
    const dx = a.x - b.x, dy = a.y - b.y;
    return Math.sqrt(dx*dx + dy*dy);
}


function nearestPickup(user) {
    let best = null, bestDist = Infinity;
    pickupPoints.forEach(p => {
        const d = distance(user, p);
        if (d < bestDist) { bestDist = d; best = p; }
    });
    return { point: best, dist: bestDist };
}


function estimateDays(pvz, user) {
    const d = distance(user, pvz);
    const extra = Math.ceil(d / 10);
    return { total: pvz.baseDays + extra, dist: d.toFixed(1), extra };
}

function openCheckout() {
    if (!currentUser) {
        alert('Войдите, чтобы оформить заказ');
        openLogin();
        return;
    }
    if (!Object.keys(cart).length) {
        alert('Корзина пуста');
        return;
    }

    const sel = document.getElementById('pvzSelect');
    sel.innerHTML = pickupPoints.map(p => {
        const est = estimateDays(p, users[currentUser]);
        return `<option value="${p.id}">${p.name} — ~${est.total} дн. (расст. ${est.dist})</option>`;
    }).join('');


    const near = nearestPickup(users[currentUser]);
    sel.value = near.point.id;
    document.getElementById('nearestHint').textContent =
        `Ближайший ПВЗ: ${near.point.name} (расстояние ${near.dist.toFixed(1)})`;

    updateDeliveryPreview();
    document.getElementById('checkoutModal').classList.add('active');
    logAction(`Открыто оформление заказа: ${currentUser}`);
}

function updateDeliveryPreview() {
    if (!currentUser) return;
    const pvzId = document.getElementById('pvzSelect').value;
    const pvz = pickupPoints.find(p => p.id === pvzId);
    const est = estimateDays(pvz, users[currentUser]);

    // Стоимость доставки: фиксированная база + доплата за удалённость
    const cost = 200 + Math.round(est.dist * 10);
    const date = new Date();
    date.setDate(date.getDate() + est.total);

    document.getElementById('deliveryInfo').innerHTML =
        `ПВЗ: <b>${pvz.name}</b><br>` +
        `Расстояние от клиента: ${est.dist} у.е.<br>` +
        `Срок доставки: <b>${est.total} дн.</b> (база ${pvz.baseDays} + ${est.extra} за удалённость)<br>` +
        `Ожидаемая дата: <b>${date.toLocaleDateString('ru-RU')}</b><br>` +
        `Стоимость доставки: <b>${cost} ₽</b>`;
    return { pvz, est, cost, date };
}

function confirmOrder() {
    if (!currentUser) return;
    const info = updateDeliveryPreview();


    for (const [id, qty] of Object.entries(cart)) {
        if (qty > (stock[id] || 0)) {
            alert(`Товара id=${id} недостаточно на складе`);
            return;
        }
    }


    let total = 0;
    for (const [id, qty] of Object.entries(cart)) {
        stock[id] -= qty;
        const p = products.find(x => x.id === Number(id));
        total += p.price * qty;
        logAction(`Списано со склада: ${p.name} × ${qty} (осталось ${stock[id]})`);
    }

    const orderId = 'ORD-' + Date.now().toString().slice(-6);
    logAction(`Заказ ${orderId} оформлен: сумма ${total} ₽, доставка ${info.cost} ₽, ПВЗ ${info.pvz.name}, срок ${info.est.total} дн.`);

    alert(
        `Заказ ${orderId} оформлен!\n` +
        `Сумма товаров: ${total} ₽\n` +
        `Доставка: ${info.cost} ₽\n` +
        `ПВЗ: ${info.pvz.name}\n` +
        `Срок: ~${info.est.total} дн. (до ${info.date.toLocaleDateString('ru-RU')})`
    );

    cart = {};
    renderCart();
    renderProducts();
    document.getElementById('checkoutModal').classList.remove('active');
}

function closeCheckout() {
    document.getElementById('checkoutModal').classList.remove('active');
}


window.addEventListener('DOMContentLoaded', () => {
    renderProducts();
    renderCart();
    logAction('Сайт загружен. Пользователь: Гость');
});