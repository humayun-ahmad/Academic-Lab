@extends('layouts.main')
    
    @section('content')
    
        <h2>Update Book information</h2>

        <form action="{{ route('books.update',['book' => $book]) }}" method="POST">
            @csrf 
            @method('PATCH')
            <div class="mb-3">
                <label for="exampleInputEmail1" class="form-label">Title</label>
                <input type="text" class="form-control" name="title" value="{{ $book->title }}">
                @error('title')
                    <small class="text-danger">{{ $message }}</small>
                @enderror
            </div>
            <div class="mb-3">
                <label for="exampleInputEmail1" class="form-label">Author</label>
                <input type="text" class="form-control" name="author" value="{{ $book->author }}">
                @error('author')
                    <small class="text-danger">{{ $message }}</small>
                @enderror
            </div>
            <div class="mb-3">
                <label for="exampleInputEmail1" class="form-label">Price</label>
                <input type="Price" class="form-control" name="price" min=0 value="{{ $book->price }}">
                @error('price')
                    <small class="text-danger">{{ $message }}</small>
                @enderror
            </div>
            <div class="mb-3">
                <label for="exampleInputEmail1" class="form-label">ISBN</label>
                <input type="text" class="form-control" name="isbn" value="{{ $book->isbn }}">
                @error('isbn')
                    <small class="text-danger">{{ $message }}</small>
                @enderror
            </div>
            <button type="submit" class="btn btn-primary">Submit</button>
        </form>


    @endsection