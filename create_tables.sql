create table table_account
(
	id integer not null
		constraint table_account_pk
			primary key autoincrement,
	login text not null,
	password text not null,
	is_active integer default 1 not null
);

create table table_person
(
	id integer not null
		constraint table_person_pk
			primary key autoincrement
		constraint table_person_table_account_id_fk
			references table_account,
	first_name text not null,
	last_name text not null,
	birth_day text not null,
	email text not null,
	tel text not null
);

INSERT INTO table_account (login, password, is_active)
VALUES ('admin', '12345', 1),
		('guest', '123', 1),
		('adm', '0000', 0);

INSERT INTO table_person (first_name, last_name, birth_day, email, tel)
VALUES ('Admin', 'Admin', '2020-12-20', 'admin@admin.admin', '+7 (123) 123-45-67'),
		('Guest', 'Guest', '2020-12-20', 'guest@guest.guest', '+7 (123) 123-45-67'),
		('Adm', 'Adm', '2020-12-19', 'adm@adm.adm', '+71231234567');