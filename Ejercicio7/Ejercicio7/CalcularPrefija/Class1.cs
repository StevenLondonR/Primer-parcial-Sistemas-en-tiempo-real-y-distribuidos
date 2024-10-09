namespace CalcularPrefija
{
    public class Class1
    {

        public double EvaluatePrefix(string expression)
        {
            // Divide la expresión en tokens (operador y operandos)
            string[] tokens = expression.Split(' ');
            Stack<string> stack = new Stack<string>();

            // Recorremos los tokens desde el final hacia el principio (porque es notación prefija)
            for (int i = tokens.Length - 1; i >= 0; i--)
            {
                stack.Push(tokens[i]);
            }

            // Llamamos a la función recursiva que evalúa la expresión
            return EvaluateStack(stack);
        }

        static double EvaluateStack(Stack<string> stack)
        {
            // Obtenemos el siguiente token (que puede ser un operador o un número)
            string token = stack.Pop();

            // Verificamos si el token es un operador
            if (IsOperator(token))
            {
                // Si es un operador, necesitamos obtener los operandos recursivamente
                double operand1 = EvaluateStack(stack); // Primer operando
                double operand2 = EvaluateStack(stack); // Segundo operando

                // Realizamos la operación correspondiente
                switch (token)
                {
                    case "+":
                        return operand1 + operand2;
                    case "-":
                        return operand1 - operand2;
                    case "*":
                        return operand1 * operand2;
                    case "/":
                        return operand1 / operand2;
                    default:
                        throw new ArgumentException("Operador desconocido");
                }
            }
            else
            {
                // Si no es un operador, asumimos que es un número y lo convertimos
                return double.Parse(token);
            }
        }

        // Función auxiliar para verificar si un token es un operador
        static bool IsOperator(string token)
        {
            return token == "+" || token == "-" || token == "*" || token == "/";
        }

    }
}
