# LogDataFromESP32
This project is for reading CAN-Bus and log the Data to SQL Database

At first I set up the conenction from the ESP32 to my database which runs on XAMPP. Im just writing some test data at the moment. Later the ESP32 will be used to read CAN data with the help of MCP2515 Module and safe it in the database.

Now the ESP32 just increases a variable and send it to the server by HTTP GET request.

The connect.php file takes those test data and logs it into the database.

the "Databank.java" file is used to read that data from the database and will be used later to plot the real data or create logfiles or something.
