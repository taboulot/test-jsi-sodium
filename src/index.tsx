export function compute(n: number): string {
  //@ts-expect-error global not typed
  return global.computeFibo(n);
}

export function randomNumber(): string {
  //@ts-expect-error global not typed
  return global.randomNumber();
}
