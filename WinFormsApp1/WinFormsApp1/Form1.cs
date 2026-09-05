namespace WinFormsApp1
{
    public partial class Form1 : Form
    {

        private List<string> dataList = new List<string>
        {
            "Яблоко",
            "Банан",
            "Апельсин",
            "Груша",
            "Киви",
            "Манго",
            "Дыня",
            "Клубника",
            "Чай",
            "Кофе"
        };

        public Form1()
        {
            InitializeComponent();
            LoadAllData();
        }

        private void LoadAllData()
        {
            listBox1.Items.Clear();
            foreach (string item in dataList)
            {
                listBox1.Items.Add(item);
            }
        }


        private void button1_Click(object sender, EventArgs e)
        {
            string searchQuery = textBox1.Text.Trim();

            listBox1.Items.Clear();

            if (string.IsNullOrEmpty(searchQuery))
            {
                LoadAllData();
                return;
            }

            bool found = false;
            foreach (string item in dataList)
            {
                if (item.IndexOf(searchQuery, StringComparison.OrdinalIgnoreCase) >= 0)
                {
                    listBox1.Items.Add(item);
                    found = true;
                }
            }

            if (!found)
            {
                listBox1.Items.Add("Не найдено");
            }
        }
    }
}

