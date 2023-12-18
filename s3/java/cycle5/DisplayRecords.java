public class DisplayRecords {
    public static void main(String[] args) {
        try {
            // Simulating connecting to the database
            System.out.println("Connecting to the database...");

            // Simulating fetching data from the database
            System.out.println("Fetching data from the database...");
            String[][] records = {
                {"John Doe", "25"},
                {"Jane Smith", "30"},
                {"Bob Johnson", "22"},
                {"Alice Jones", "28"},
                {"Charlie Brown", "35"},
                {"Eva Williams", "29"},
                {"Frank Miller", "26"},
                {"Grace Davis", "31"},
                {"Henry Wilson", "27"},
                {"Isabel White", "33"}
            };

            // Printing records
            System.out.println("ID\tName\t\tAge");
            for (int i = 0; i < records.length; i++) {
                System.out.println((i + 1) + "\t" + records[i][0] + "\t" + records[i][1]);
            }

            // Simulating closing the database connection
            System.out.println("Closing the database connection...");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
