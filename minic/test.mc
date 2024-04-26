prueba () {
    const a = 1;
    const b = 2 * 3;
    var c;
    var d = 5 + 2, e = 9 / 3;

    print ("Inicio del programa\n");

    print ("Introduce el valor de \"c\":\n");
    read (c);
    /*prueba if*/
    if (c!=0) print ("\"c\" no era nulo.", "\n");
    else print ("\"c\" si era nulo.", "\n");
    print("Valores de d hasta que valga 0\n");
    /* prueba while */
    while (d!=0) {
        print ("\"d\" vale", d, "\n");
        d = d - 1;
    }
    print("Valores de e hasta que valga 0\n");
    /* prueba do - while */
    do {
        print ("\"e\" vale", e, "\n");
        e = e - 1;
    } while(e>0);
    print("Valores de c hasta que valga 10\n");
    /* prueba for */
    for(c=1;c<10:2){
        print("\"c\" vale", c, "\n");
    }
	print ("Final","\n");
}