import { Component } from '@angular/core';
import { Log } from './decorator/log_decorator';
import { Debounce } from './decorator/debonce_decorator';

@Component({
  selector: 'app-root',
  standalone: true,
  template: `
    <div style="padding: 20px; font-family: sans-serif;">
      <h2>Проверка декораторов</h2>
      
      <div style="margin-bottom: 20px;">
        <input (input)="onSearch($event)" placeholder="Введите текст ..." style="padding: 8px; width: 300px;" />
      </div>

      <div>
        <button (click)="calculate(10, 5)" style="padding: 8px 16px; cursor: pointer;">Посчитать</button>
      </div>
    </div>
  `
})
export class App {
  
  @Log
  calculate(a: number, b: number): number {
    return a + b;
  }

  @Debounce(500)
  onSearch(event: Event) {
    const value = (event.target as HTMLInputElement).value;
    console.log('Поиск по запросу:', value);
  }
}