<html>
    <body>
        <?php
        //define properties for example database
        $dbname = 'kinobuchungendb';
        $dbuser = 'root';
        $dbpass = '';
        $dbhost = 'localhost';

        //connect to database
        $connect = @mysqli_connect($dbhost ,$dbuser,$dbpass, $dbname );
        
        //test if connection succeeded
        if($conenct){
            echo "Error: " . mysqli_connect_error();
            exit();
        }
        //give feedback that connection succeeded
        echo "Connection Sucess!<br><br>";

        //get values for name and id
        $id = $_GET["id_"];
        $name_ = $_GET["name_"];
    
        echo $id;
        echo $name_;

        //insert values to database (email = 'testmail'...just for testing)
        $query = "INSERT INTO besucher (id_besucher,name,email)VALUES($id,$name_,'testmail');";
        $result = mysqli_query($connect,$query);

        echo "Insertion Sucess!<br>";
        ?>
        </body>
        </html>