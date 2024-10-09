namespace Ejercicio8
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            CalcularPrefija.Class1 calcu = new CalcularPrefija.Class1();

            String texto = textBox1.Text;
            double salida = calcu.EvaluatePrefix(texto);
            textBox2.Text = salida.ToString();

        }

        private void Enviar(string letra)
        {
            string a = textBox1.Text;
            if (a.Equals(null) || a.Equals(""))
            {
                textBox1.Text = letra;
            }
            else
            {
                textBox1.Text = a + " " + letra;
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Enviar("7");
        }

        private void button11_Click(object sender, EventArgs e)
        {
            Enviar("0");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Enviar("1");
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Enviar("2");
        }

        private void button10_Click(object sender, EventArgs e)
        {
            Enviar("3");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Enviar("4");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Enviar("5");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Enviar("6");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Enviar("8");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Enviar("9");
        }

        private void button12_Click(object sender, EventArgs e)
        {
            Enviar("+");
        }

        private void button13_Click(object sender, EventArgs e)
        {
            Enviar("-");
        }

        private void button14_Click(object sender, EventArgs e)
        {
            Enviar("*");
        }

        private void button15_Click(object sender, EventArgs e)
        {
            Enviar("/");
        }

        private void button16_Click(object sender, EventArgs e)
        {
            textBox1.Text="";
        }
    }
}
