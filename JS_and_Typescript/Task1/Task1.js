const products = [
    {id: 1, name: "Ноутбук", price: 63000, stock: 5},
    {id: 2, name: "Смартфон", price: 43000, stock: 15},
    {id: 3, name: "Батарейки", price: 5000, stock: 30},
]

const cart = [];

function buy(productId, qty=1){
    const product = products.find(p=>p.id === productId);
    if(!product)
        return console.log ("Товар не найден");
    if(product.stock < qty)
        return console.log ("Недостаточо на складе");

    product.stock -= qty;
    cart.push({...product, qty, boughtAt: new Date() });
    console.log(`Куплено: ${product.name} x${qty}`);
}

function refund(productId) {
    const idx = cart.findIndex(i => i.id === productId);
    if (idx === -1) return console.log("Товара нет в корзине");

    const [item] = cart.splice(idx, 1);
    const product = products.find(p => p.id === productId);
    product.stock += item.qty;
    console.log(`Возврат: ${product.name} x${item.qty}`);
}

function exchange(oldId, newId) {
    const oldItem = cart.find(i => i.id === oldId);
    if (!oldItem) 
        return console.log("Товара для обмена нет");

    const newProduct = products.find(p => p.id === newId);
    if (!newProduct || newProduct.stock < 1) 
        return console.log("Нет товара для обмена");

    refund(oldId);
    buy(newId, oldItem.qty);
    console.log("Обмен выполнен");
}

buy(1,2);
buy(2);
refund(2);
exchange(1, 3);
console.log(products);


