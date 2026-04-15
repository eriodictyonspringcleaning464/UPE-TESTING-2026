# Guia de Demo: Analisis Estatico con SonarQube

## Objetivo
Mostrar como SonarQube detecta bugs sin ejecutar el programa (analisis estatico).

---

## PARTE 1: Mostrar el bug en vivo (5 min)

### Compilar y ejecutar

```bash
cd demo-sonar
make clean all
./demo_sonar_bug
```

**Salida esperada:**
```
Resultado 1: 5
Resultado 2: 5
```

### Explicar

> "Resultado 1 es correcto: 10 / 2 = 5.
> Pero Resultado 2 tambien dice 5... y la division era 10 / 0.
> No crasheo, no dio error. Simplemente devolvio basura."

**Preguntar a los alumnos:** "Por que no crasheo?"

**Respuesta:** Cuando `b == 0`, el `if (b != 0)` no entra, y retorna `resultado`
que nunca fue inicializada. El `5` es lo que quedo en memoria de la llamada anterior.

---

## PARTE 2: SonarQube lo detecta (10 min)

### Abrir el dashboard

https://sonarcloud.io/dashboard?id=tinchoram_UPE-TESTING-2026

### Mostrar el Quality Gate

> "El Quality Gate FALLO. SonarQube analizo el codigo sin ejecutarlo
> y encontro problemas."

### Navegar a los issues

- **Bug:** variable `resultado` potencialmente no inicializada (linea 27)
- **Code smell:** condicion imposible `if (a == 0)` dentro de `if (a > 0)` (linea 16) — codigo muerto

### Mostrar metricas

- Densidad de defectos = cantidad de issues / lineas de codigo
- Reliability Rating
- Maintainability Rating

### Punto clave

> "No corrimos ningun test. No ejecutamos el programa.
> SonarQube leyo el codigo fuente y encontro estos bugs
> solo analizando la logica. Eso es **analisis estatico**."

---

## PARTE 3: Corregir y comparar (5 min)

### Reemplazar el codigo por la version corregida

```c
#include <stdio.h>

int calcularDivisionSegura(int a, int b)
{
    int resultado = 0;  // inicializada

    if (b != 0)
    {
        resultado = a / b;
    }

    return resultado;  // siempre tiene un valor definido
}

int main(void)
{
    int r1 = calcularDivisionSegura(10, 2);
    int r2 = calcularDivisionSegura(10, 0);

    printf("Resultado 1: %d\n", r1);
    printf("Resultado 2: %d\n", r2);

    return 0;
}
```

### Compilar, ejecutar y ver la diferencia

```bash
make clean all
./demo_sonar_bug
```

**Salida esperada:**
```
Resultado 1: 5
Resultado 2: 0
```

> "Ahora Resultado 2 es 0, un valor predecible y controlado."

### Volver a correr SonarQube

```bash
cd ..
./build-wrapper-macosx-x86/build-wrapper-macosx-x86 --out-dir bw-output make -C demo-sonar clean all
sonar-scanner -Dsonar.host.url=https://sonarcloud.io -Dsonar.token=TU_TOKEN
```

> "El Quality Gate ahora pasa. Los issues desaparecen."

---

## Cierre (2 min)

> "SonarQube es una herramienta de **analisis estatico**: lee el codigo
> y busca patrones problematicos sin ejecutarlo.
>
> Es complementario a los tests: los tests verifican que el programa
> haga lo correcto, SonarQube busca problemas que podrias no haber testeado."
