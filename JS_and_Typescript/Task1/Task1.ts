interface Product {
    id: number;
    name: string;
    price: number;
    stock: number;
}

interface CartItem extends Product {
    qty: number;
    boughtAt: Date;
}

const products: Product[] = [
    { id: 1, name: "Ноутбук",  price: 75000, stock: 5 },
    { id: 2, name: "Смартфон", price: 45000, stock: 10 },
    { id: 3, name: "Наушники", price: 8000,  stock: 20 },
];

const cart: CartItem[] = [];

function buy(productId: number, qty: number = 1): void {
    const product = products.find(p => p.id === productId);
    if (!product) return console.log("Товар не найден");
    if (product.stock < qty) return console.log("Недостаточно на складе");

    product.stock -= qty;
    cart.push({ ...product, qty, boughtAt: new Date() });
    console.log(`Куплено: ${product.name} x${qty}`);
}

function refund(productId: number): void {
    const idx = cart.findIndex(i => i.id === productId);
    if (idx === -1) return console.log("Товара нет в корзине");

    const [item] = cart.splice(idx, 1);
    const product = products.find(p => p.id === productId)!;
    product.stock += item.qty;
    console.log(`Возврат: ${product.name} x${item.qty}`);
}

function exchange(oldId: number, newId: number): void {
    const oldItem = cart.find(i => i.id === oldId);
    if (!oldItem) return console.log("Товара для обмена нет");

    const newProduct = products.find(p => p.id === newId);
    if (!newProduct || newProduct.stock < 1) return console.log("Нет товара для обмена");

    refund(oldId);
    buy(newId, oldItem.qty);
    console.log("Обмен выполнен");
}

buy(1, 2);
buy(2, 1);
refund(1);
exchange(2, 3);
console.log("Остатки на складе:", products);

