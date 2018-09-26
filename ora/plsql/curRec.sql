 DECLARE
   CURSOR C is
      SELECT eno, ename, dname 
      FROM 
      emp inner join dept
      on emp.dno = dept.dno;

  emp_rec C%rowtype;
BEGIN
   OPEN C;
   LOOP
      FETCH C into emp_rec;
      EXIT WHEN C%notfound;
      DBMS_OUTPUT.put_line(emp_rec.eno || ' ' || emp_rec.ename || '   ' || emp_rec.dname);
   END LOOP;
   close C;
END;
/ 
