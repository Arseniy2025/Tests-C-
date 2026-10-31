import { Component } from '@angular/core';
import { Log } from './decorator/log_decorator';
import { Debounce } from './decorator/debonce_decorator';

@Component({
    selector: 'app-root',
    standalone: true,
    template: `
        <input (input)="onSearch($event)" placeholder="Введите текст..." />
        <button (click)="calculate(10, 5)">Посчитать</button>
    `
})
export class AppComponent {
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