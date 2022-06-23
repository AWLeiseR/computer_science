create table livraria.publisher(
	name VARCHAR,
	address VARCHAR,
	phone VARCHAR,	
	constraint pkpublisher primary key (name)
);

create table livraria.libraryBranch(
	branchId serial,
	branchName varchar,
	address varchar,
	constraint pklibraryBranch primary key (branchId)
);

create table livraria.borrower(
	cardNo serial,
	name varchar,
	address varchar,
	phone varchar,
	constraint pkborrower primary key (cardNo)
);

create table livraria.bookAuthors(
	bookId serial,
	authorName varchar,	
	constraint pkbookAuthors primary key (bookId)
);

create table livraria.book(
	bookId serial,
	title varchar,
	publisherNAme varchar,
	constraint pkBook primary key (bookId),
	constraint fkPublisherName foreign key (publisherName)
		references livraria.publisher(name)
);

create table livraria.bookCopies(
	bookId int,
	branchId int,
	noOfCopies int,
	constraint pkbookCopies primary key (bookId,branchId),
	constraint fkBookIdBookCopies foreign key (bookId)
		references livraria.book (bookId),
	constraint fkBranchIdBookCopies foreign key (branchId)
		references livraria.libraryBranch (branchId)
);

create table livraria.bookLoans(
	bookId int,
	branchId int,
	cardNo int,
	dateOut date,
	dueDate date,
	constraint pkBookLoans primary key (bookId,branchId,cardNo),
	constraint fkBookIdBookLoans foreign key (bookId)
		references livraria.book (bookId),
	constraint fkBranchId foreign key (branchId)
		references livraria.libraryBranch (branchId),
	constraint fkCardNo foreign key (cardNo)
		references livraria.borrower (cardNo)
);

/*----------insertions------------*/

INSERT INTO livraria.book(
	 title, publishername)
	VALUES ('The Lost Tribe','JFK'),
	('A volta dos que não foram', 'JFK'),
	( 'Tranças do careca','Bobs'),
	('The book','JFK'),
    ('Harry Potter e a pedra filosofal','JFK');
	
INSERT INTO livraria.bookauthors(
	authorname)
	VALUES ('Alencar'),
	('Stephen King'),
	('Stephen King'),
	('James Patterson'),
	('Mark Sullivan'),
	('J. K. Rowling');

INSERT INTO livraria.bookcopies(
	bookid, branchid, noofcopies)
	VALUES (1,4,10),
	(1,2,20),
	(1,3,20),
	(2,3,10),
	(3,3,10),
	(4,2,30),
	(5,4,40);

INSERT INTO livraria.bookloans(
	bookid, branchid, cardno,  duedate,dateout)
	VALUES (1,2,1,'2020-10-11','2020-10-15'),
	(1,2,3,'2020-10-11','2020-10-15'),
	(2,4,1,'2020-11-11','2020-11-15'),
	(3,4,3,'2020-11-11','2020-11-15'),
	(1,2,4,'2020-10-11','2020-10-15'),
	(2,4,4,'2020-11-11',current_date),
	(3,4,4,'2020-11-11','2020-11-15'),
	(1,3,4,'2020-10-11',current_date),
	(2,3,4,'2020-11-18',current_date),
	(3,3,4,'2020-11-20','2020-11-25'),
	(5,3,1,'2020-11-20','2020-11-25');

INSERT INTO livraria.borrower(
	name, address, phone)
	VALUES ('Relampago marquinhos', 'misto quente',4444444),
	('Mufaza', 'x-salada',555555555),
	('Frozen', 'x-bacon',66666666),
	('Jhonny Five','hamburguer',77777777);

INSERT INTO livraria.librarybranch(
	 branchname, address)
	VALUES ('Sharpstown','x-burguer'),
	('printed words','x-egg'),
	('Central','x-bacon');
	
insert into livraria.publisher(
	name,address,phone
)VALUES('JFK','Flower Street','99999999'),
	('MC Donalds','Grass Street','888888888'),
	('Bobs','Burguer Street','777777777');

/*------------resolution-------------*/
/*1. Create a materialized view month_borrowers that shows the data (card_no, name, address, and
phone) from the borrowers who had (or have) more than one loan whose length (i.e., the difference
between the date out and the due date) is greater than or equal to 30 days. The view should also
show the loan length, the book title and the branch name of these loans. Besides, perform updates to
the base tables, eventually run statements to make the DBMS update the view, and show the state of
the up-to-date materialized view.*/
create materialized view livraria.table1  as
select bookloans.cardno,borrower.name,borrower.address,phone, (dateout - duedate) as periodo,title, librarybranch.branchname from 
(select cardno, count(1) as counter from livraria.bookloans  where dateout - duedate >30 group by  cardno) as table1 join 
livraria.bookloans on table1.cardno=bookloans.cardno 
inner join livraria.borrower
on bookloans.cardno = borrower.cardno inner join livraria.book
on book.bookid = bookloans.bookid inner join livraria.librarybranch
on librarybranch.branchid = bookloans.branchid
where counter > 1 and dateout - duedate >30

/*2. Assume that after having deployed the database and loaded it with data, the library manager
decided to store book copies individually. From now on, the database should store an id, the
acquisition date, and the current conditions (fine, good, fair, or poor) for each copy. Book loans
should refer to a specific book copy. The attribute no_of_copies should no longer be stored in the
database. However, existing applications should "see" the database as if the schema had not been
updated for backward compatibility.

• Create a temporary table to save the current number of copies of each book in each branch.

• Implement the commands to perform the necessary change to the database schema.

• Write a query or a function that returns/shows the inconsistencies between the number of
copies of a book in a branch in the updated schema and the respective number of copies in
the temporary table. That is, identify the cases these numbers do not match.

• Insert book copies into the updated schema until there is no more such an inconsistency.
Commit the changes and drop the temporary table.

• Create a view with the same name as the old table (book_copies), showing the same content.
That is, an application could interact with the view as it was the old table.

◦ A delete from the view should trigger the deletion of the tuples corresponding to the
book copies.

◦ An update on the view to attributes book_id or branch_id should be automatically
redirected to the base tables.

◦ An update on the view reducing the number of copies cannot be accepted.

◦ An insert into the view or an update on the view increasing the number of copies should
trigger the insertion of book copy tuples such that the number of copies matches the
value provided to the update statement. The new tuples' id should be set using a
sequence, and their acquisition date should be the current date.

• Show the database state before and after executing inserts, updates and deletes on the view,
showing that the triggered actions satisfy all the specifications' points.*/

/*cria tabela temporaria com os valores da tabela do bd*/

create temporary table tempbookcopies AS
	select * from livraria.bookcopies; 

/*deleta os dados da tabela do bd*/
delete table livraria.bookcopies;

/*alterações na tabela do bd para atender as demandas*/
alter table livraria.bookcopies
	add column acquisitionDate date,
	add column currentConditions varchar,
	add column bookCopieId serial;

alter table livraria.bookcopies
	drop column noofcopies;

BEGIN;
ALTER TABLE livraria.bookcopies DROP CONSTRAINT  pkbookcopies ;
	ALTER TABLE livraria.bookcopies ADD  CONSTRAINT pkbookcopies primary KEY (bookid,branchid,bookCopieId) ;
COMMIT;

alter table livraria.individualbookcopies
		add constraint ukbookcopieid unique (bookcopieid)

RENAME TABLE livraria.bookcopies TO livraria.individualbookcopies;

/*alteracao no booloans para aceitar um id individual para cada copia do livro*/
alter table livraria.bookloans add column bookIndividualId int

alter table livraria.bookloans 
		add constraint fkbookloansIndividualid foreign key (bookindividualid) 
		references livraria.individualbookcopies (bookcopieid)

UPDATE livraria.bookloans as b 
SET bookindividualid = (SELECT bookcopieid FROM livraria.individualbookcopies as c 
		  WHERE b.bookid = c.bookid 
		  AND b.branchid = c.branchid LIMIT 1)

begin;
	alter table livraria.bookloans drop constraint pkbookloans;
	alter table livraria.bookloans add constraint pkbookloans primary key (bookid,branchid,cardno,bookindividualid);
commit;

/*funcao para contar numero de copias de cada livro e branch*/
create or replace function livraria.countNumOfBooks()
	returns table (bookid int, branchid int, noofcopies bigint) as $$
		select bookid,branchid, COUNT(1)
			as noofcopies from livraria.individualbookcopies group by bookid, branchid;
$$ LANGUAGE SQL;

/*query que mostra as inconscistencias*/
select tempbookcopies.bookid, tempbookcopies.branchid,(tempbookcopies.noofcopies) as tempnoofcopies, 
(case when table1.noofcopies is not null 
	then table1.noofcopies
	else 0	end)
	as bdnoofcopies,
(case when table1.noofcopies is not null 
	then tempbookcopies.noofcopies - table1.noofcopies
	else tempbookcopies.noofcopies	end)
	as diferenca
from livraria.countnumofbooks() as table1 full join tempbookcopies 
on table1.bookid = tempbookcopies.bookid and table1.branchid = tempbookcopies.branchid
where tempbookcopies.noofcopies - table1.noofcopies > 0 or table1.noofcopies is null

/* refazer a tabela do bd com base na tabel temporaria */
CREATE OR REPLACE FUNCTION livraria.rebuildBDRow(bookid int,branchid int,noofcopies int, conditions varchar)
  RETURNS BOOLEAN AS $$
DECLARE
  c RECORD;
BEGIN
	FOR c IN 1..noofcopies LOOP
		insert into livraria.individualbookcopies (bookid,branchid,acquisitiondate, currentconditions)
		values(bookid,branchid,current_date,conditions);

	  END LOOP;
	  RETURN true;
END;
$$ LANGUAGE PLPGSQL;

/*Chamadas da funcao para remover as inconscistencias com base na query de comparacao*/
select livraria.rebuildBDRow(3,3,5,'good');
select livraria.rebuildBDRow(4,2,30,'fine');
select livraria.rebuildBDRow(5,4,40,'fine');


/* cria view para a aplicação enxergar o bd como o antigo*/
CREATE VIEW livraria.bookCopies as
	select * from livraria.countnumofbooks()

/* funcao para o trigger de delete*/
create or replace function livraria.deleteTuplesTableBd()
returns trigger as $$
	begin
		delete from livraria.individualbookcopies where bookid = OLD.bookid and branchid = OLD.branchid ;
		return null;
	end;
	$$ language plpgsql;

CREATE TRIGGER deletaViewTuple 
   INSTEAD OF DELETE
   ON livraria.bookcopies
   FOR EACH row
       EXECUTE PROCEDURE livraria.deleteTuplesTableBd()

/* funcao para o trigger de update noofcopies*/
create or replace function livraria.updateTuplesTableBd()
returns trigger as $$
	begin
		if old.noofcopies > new.noofcopies then
			RAISE EXCEPTION 'Operação invalida';
		elsif old.noofcopies < new.noofcopies then
			perform livraria.rebuildbdrow(old.bookid,old.branchid, CAST (new.noofcopies-old.noofcopies as int),'fine');
			return new;	
		elsif old.bookid <> new.bookid or old.branchid <> new.branchid then
			update livraria.individualbookcopies 
				set bookid = new.bookid, branchid = new.branchid 
				where bookid = old.bookid and branchid = old.branchid;
			return new;
		end if;
	end;
	$$ language plpgsql;

CREATE TRIGGER updateViewTuple 
   INSTEAD OF UPDATE 
   ON livraria.bookcopies
   FOR EACH  ROW
       EXECUTE PROCEDURE livraria.updateTuplesTableBd()

/*trigger de insert*/

create or replace function livraria.insertViewTuplesFunc()
	returns trigger as $$
	begin
		perform livraria.rebuildbdrow(new.bookid,new.branchid,cast (new.noofcopies as int),cast ('good' as varchar));
		return new;
	end;
	$$ language plpgsql;

CREATE TRIGGER insertViewTuple
   Instead of INSERT
   ON livraria.bookcopies
   FOR EACH ROW 
       EXECUTE PROCEDURE livraria.insertViewTuplesFunc()

/*3. Write a procedure to detect and reconcile authors who have inconsistent entries in the book
authors table. This procedure is an example of entity matching, which is a complex task but will be
quite simplified for this exercise.
Assume that authors can have inconsistent entries due to typos (e.g., John Joseph Powell and John
Joseph Powel) or abbreviations (e.g., John Joseph Powell and John J. Powell). Assume also that
typos are constrained to at most two non-matching characters. This contraint allows detecting
missing (e.g., Powel) or exceeding caracters (e.g., Poweell), and character switches (e.g., Pwoell).
Also, assume that author names are either: 
i) given name, middle name, and surname (e.g., John Joseph Powell); or 
ii) given name, middle initial, and surname (e.g., John J. Powell).
 Duplicates
regarding middle name or middle initial must match the first letter (i.e., John Joseph Powell and
John A. Powell are not duplicates).
The procedure should:
• detect duplicates;
• identify the most frequent between the duplicated values and eliminate the duplication by
updating the least frequent value with the most frequent one (e.g., if there is 5 occurrences of
John J. Powell in the database and only one occurrence of John J. Pwoell, then the procedure
should update John J. Pwoell to John J. Powell);
• log every duplicate elimination, saving the book id, the old author name, the new author
name, and the update timestamp to a log table.
Notice that your procedure implementation can rely on cursors, call built-in or user-defined
functions, use triggers, etc. Use the DBMS resources as needed. Submit a script containing all
statements needed to implement and test the procedure (i.e., the script should include proper data
insertions to test the procedure).*/

INSERT INTO livraria.bookauthors(
	authorname)
	VALUES ('Alencarr'),
	('Stephen Kking'),
	('Stephen Knig'),
	('James Paterson'),
	('Mark Sulivan'),
	('J. K. Rolwing'),
	('Stephen K.');

create or replace function livraria.separarnomes()
	returns table (primeiro text,segundo text, terceiro text) as $$
		begin
		return query
		SELECT SPLIT_PART(authorname, ' ', 1) as primeiro,
			SPLIT_PART(authorname, ' ', 2),SPLIT_PART(authorname, ' ', 3) from livraria.bookauthors;
			
		end;
$$ language plpgsql;

create or replace function livraria.tamanhonome()
returns table(tamPrimeiro int, tamSegundo int, tamTerceiro int) as $$
	begin
		return query
		select char_length(primeiro) ,char_length(segundo),char_length(terceiro) 
		from livraria.separarnomes() ;
	end;
	$$ language plpgsql;

	select left(segundo,1) as initial from livraria.separarnomes() group by initial