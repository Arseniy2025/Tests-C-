import { Component, signal } from '@angular/core';
import { CommonModule } from '@angular/common';

interface Product {
  id: number;
  name: string;
  price: number;
}

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [CommonModule], 
  templateUrl: './app.html',
  styleUrls: ['./app.css']
})
export class App { 
  isLoggedIn = signal(false);

  products = signal<Product[]>([
    { id: 1, name: 'Ноутбук', price: 12000 },
    { id: 2, name: 'Мышь', price: 250 },
    { id: 3, name: 'Клавиатура', price: 800 },
    { id: 4, name: 'Монитор', price: 3000 }
  ]);

  toggleAuth() {
    this.isLoggedIn.update(status => !status);
  }
}