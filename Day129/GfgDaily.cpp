    isRotated(str1, str2)
    {
        // code here
        return str2.slice(-2) + str2.slice(0, -2) == str1 ||
                str2.slice(2) + str2.slice(0, 2) == str1;
    }