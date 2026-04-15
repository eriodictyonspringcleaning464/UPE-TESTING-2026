float RealizaCalculo(int a, int b)
{
    float resultado;

    if (a > 0)
    {
        if (a == 0)
        {
            resultado = 0;
        }
        else
        {
            if (a > b)
            {
                if (b != 0)
                {
                    resultado = (a * 2) / b;
                }
            }
            else
            {
                if (b != 0)
                {
                    resultado = a / b;
                }
            }
        }
    }
    else
    {
        resultado = 0;
    }

    return resultado;
}