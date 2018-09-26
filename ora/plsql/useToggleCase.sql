DECLARE
 data varchar(20);
BEGIN
 data := '&string';
 toggleCase(data);
 DBMS_OUTPUT.PUT_LINE('you entered ' || data);
END;
/