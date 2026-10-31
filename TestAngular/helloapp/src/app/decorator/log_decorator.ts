export function Log(
    target: any,
    propertyKey: string,
    descriptor: PropertyDescriptor
){
    const original = descriptor.value;

    descriptor.value = function (...args: any[]){
        console.log(`[${propertyKey}] Вызван с аргументами`, args);
        const result = original.apply(this, args);
        console.log(`[${propertyKey}] Вернул результат:`, result);
        return result;
    };
    return descriptor;
}