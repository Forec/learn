function mul(N)
    if N == 0 then
        return 1;
    else
        return N * mul(N-1);
    end;
end;

function Messages()
    FirstName = "Forec"
    LastName = "Wang"
    FullName = "Name: " .. FirstName .. " " .. LastName;
    Pi = 3.1415926
    PiString = "Pi: " .. Pi;
    PrintStringList(FullName, PiString, "Have fun!");
end;