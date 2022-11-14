package main

import (
  "fmt"
  "reflect"
  "strconv"
)

func sumar(a int, b int) int {
    return a + b
}

func main() {
    fmt.Println(sumar(6, 5))
    var b bool
    fmt.Println(b)
    var edad int = 33
    const PI float32 = 3.1416

    var alumnos [4]string
    alumnos[0] = "Ana"
    alumnos[1] = "Brenda"
    alumnos[2] = "Carmen"
    alumnos[3] = "David"


    var alumno string = "Jose Luis"
    var edad int = 22
    var peso float64 = 85.5
    fmt.Println(reflect.TypeOf(alumno))
    fmt.Println(reflect.TypeOf(edad))
    fmt.Println(reflect.TypeOf(peso))

    var mayorDeEdad string = "true"
    boolVal, _ := strconv.ParseBool(mayorDeEdad)
    fmt.Println(boolVal, reflect.TypeOf(boolVal))

    strVal := strconv.FormatBool(mayorDeEdad)
    fmt.Println(strVal, reflect.TypeOf(strVal))
    
}
