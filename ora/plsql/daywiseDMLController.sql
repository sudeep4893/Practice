create or replace trigger daywiseDMLController
before
insert or update or delete
on
emp

DECLARE
  day varchar(15);

BEGIN
  day := to_char(sysdate, 'day');
  --day is a 9 letter word with/without blanks padded to right 
  day := rtrim(day, ' ');
  --day is a word without rpadding
  
  IF day = 'saturday'  AND INSERTING THEN
    raise_application_error(-20001, 'INSERT not allowed on SATURDAY');
  ELSIF day = 'sunday'  AND DELETING THEN
    raise_application_error(-20002, 'DELETE not allowed on SUNDAY');
  ELSIF day = 'monday'  AND UPDATING THEN
    raise_application_error(-20003, 'UPDATE not allowed on MONDAY');
  END IF;  

END;
/
