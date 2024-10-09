namespace Ejercicio9Image
{
    public partial class Form1 : Form
    {
        OpenFileDialog openFileDialog1 = new OpenFileDialog();
        Bitmap originalImage;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "Archivos de Imagen|*.jpg;*.jpeg;*.png;*.bmp";

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
               
                pictureBox1.Image = Image.FromFile(openFileDialog1.FileName);

                pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;

                originalImage = new Bitmap(openFileDialog1.FileName);
            }


        }

        private void button2_Click(object sender, EventArgs e)
        {


            // filtro Laplaciano 
            double[,] kernel = new double[,]
            {
                { -1, -1, -1 },
                { -1,  8, -1 },
                { -1, -1, -1 }
            };

            Bitmap resultImage = ApplyMatrix(originalImage, kernel);

            pictureBox2.Image = resultImage;
            pictureBox2.SizeMode = PictureBoxSizeMode.Zoom;
        }

        private Bitmap ApplyMatrix(Bitmap originalImage, double[,] kernel)
        {
            int width = originalImage.Width;
            int height = originalImage.Height;

            Bitmap resultImage = new Bitmap(width, height);

            for (int y = 1; y < height - 1; y++)
            {
                for (int x = 1; x < width - 1; x++)
                {
                    double red = 0, green = 0, blue = 0;

                    for (int ky = -1; ky <= 1; ky++)
                    {
                        for (int kx = -1; kx <= 1; kx++)
                        {
                            Color pixelColor = originalImage.GetPixel(x + kx, y + ky);

                            red += pixelColor.R * kernel[ky + 1, kx + 1];
                            green += pixelColor.G * kernel[ky + 1, kx + 1];
                            blue += pixelColor.B * kernel[ky + 1, kx + 1];
                        }
                    }

                    int finalRed = Math.Min(Math.Max((int)red, 0), 255);
                    int finalGreen = Math.Min(Math.Max((int)green, 0), 255);
                    int finalBlue = Math.Min(Math.Max((int)blue, 0), 255);

                    resultImage.SetPixel(x, y, Color.FromArgb(finalRed, finalGreen, finalBlue));
                }
            }

            return resultImage;
        }

    }
}
