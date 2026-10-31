export function Debounce(delay: number = 300): MethodDecorator {
    return function (
        target: any,
        propertyKey: string | symbol,
        descriptor: PropertyDescriptor
) {
    const original = descriptor.value;
    let timer: ReturnType<typeof setTimeout>;

    descriptor.value = function (...args: any[]) {
        clearTimeout(timer);
        timer = setTimeout(() => original.apply(this, args), delay);
    };

    return descriptor;
    };
}