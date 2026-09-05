clear
c=0
FILE="addressbook.txt"

validate_phone() {
    local phone=$1
    [[ $phone =~ ^[0-9]{10}$ ]]
}

validate_email() {
    local email=$1
    [[ $email =~ ^[a-z0-9._%+-]+@[a-z]+\.[a-z]{2,4}$ ]]
}

while test $c != 7
do
    echo "1-> Create  2-> View  3-> Insert  4-> Delete  5-> Modify  6-> Search  7-> Exit"
    read c

    case "$c" in

    "1")
    echo "Enter name for address book file:"
    read FILE
    > "$FILE"
    echo "Address book '$FILE' created successfully."
    ;;

    "2")
    echo "------ Address Book ------"
    if [[ -s $FILE ]]; then
        cat "$FILE"
    else
        echo "Address book is empty"
    fi
    ;;

    "3")
    echo "Enter number of records to insert:"
    read n
    it=1
    while [ $it -le $n ]
    do
        echo "Enter ID:"
        read id

        echo "Enter Name:"
        read name
        pname="^[A-Za-z]+$"
        while [[ ! "$name" =~ $pname ]]
        do
            echo "Invalid name. Please enter alphabetic characters only:"
            read name
        done

        echo "Enter Address:"
        read addr
        paddr="^[A-Za-z0-9 ,.-]+$"
        while [[ ! "$addr" =~ $paddr ]]
        do
            echo "Enter valid address:"
            read addr
        done

        echo "Enter Phone number (10 digits):"
        read ph
        while ! validate_phone "$ph"; do
            echo "Invalid phone number. Enter 10 digits:"
            read ph
        done

        echo "Enter Email:"
        read em
        while ! validate_email "$em"; do
            echo "Invalid email format. Please enter again:"
            read em
        done

        echo "$id,$name,$addr,$ph,$em" >> "$FILE"
        echo "$it record entered."
        it=`expr $it + 1`
    done
    ;;

    "4")
    echo "Enter ID to delete:"
    read did
    if grep -q "^$did," "$FILE"; then
        grep -v "^$did," "$FILE" > temp.txt && mv temp.txt "$FILE"
        echo "Record with ID=$did deleted."
    else
        echo "Record with ID=$did not found."
    fi
    ;;

    "5")
    echo "Enter ID to modify:"
    read mid
    if grep -q "^$mid," "$FILE"; then
        grep -v "^$mid," "$FILE" > temp.txt
        echo "Enter new details:"

        echo "Enter Name:"
        read name
        pname="^[A-Za-z]+$"
        while [[ ! "$name" =~ $pname ]]
        do
            echo "Invalid name. Please enter alphabetic characters only:"
            read name
        done

        echo "Enter Address:"
        read addr
        paddr="^[A-Za-z0-9 ,.-]+$"
        while [[ ! "$addr" =~ $paddr ]]
        do
            echo "Enter valid address:"
            read addr
        done

        echo "Enter Phone number (10 digits):"
        read ph
        while ! validate_phone "$ph"; do
            echo "Invalid phone number. Enter 10 digits:"
            read ph
        done

        echo "Enter Email:"
        read em
        while ! validate_email "$em"; do
            echo "Invalid email format. Please enter again:"
            read em
        done

        echo "$mid,$name,$addr,$ph,$em" >> temp.txt
        mv temp.txt "$FILE"
        echo "Record modified successfully."
    else
        echo "Record with ID=$mid not found."
    fi
    ;;

    "6")
    echo "Enter keyword to search (ID/Name/Phone/Email):"
    read key
    if grep -i "$key" "$FILE"; then
        echo "Record(s) found."
    else
        echo "No matching record found."
    fi
    ;;

    "7")
    echo "Exit"
    exit
    ;;

    esac
done
exit

//chmod +x Assignment1_B.sh
//Assignment1_B.sh
