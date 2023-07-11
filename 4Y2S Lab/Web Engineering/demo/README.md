Laravel CRUD + Seeding + Searching + PDF Download in one project

Project Link - https://github.com/SajeebChakraborty/CRUD-pdf-search-laravel

Steps For Running this project
1. Clone this project.
2. Rename .env.example file to .env
3. Create new database by heidiSQL or phpmyadmin
4. Set Database name 
	--> For this,first go to env file and set DB_DATABASE=your_database_name
5. Run command -> 
	i) composer update 
	ii) php artisan key:generate
	iii) php artisan migrate
	iv) php artisan db:seed --class=BookSeeder
	v) php artisan serve
6.Now check in browser section
	by --> http://localhost:8000/book-list

Asibul Tutorial: https://www.youtube.com/@mdasibulhasanshanto601