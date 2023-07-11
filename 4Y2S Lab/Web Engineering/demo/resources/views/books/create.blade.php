@extends('layouts.main')
    
    @section('content')
    
        <h2>Create Book Page</h2>

        <form action="{{ route('books.store') }}" method="POST">
            @csrf 
            <div class="mb-3">
                <label for="exampleInputEmail1" class="form-label">Title</label>
                <input type="text" class="form-control" name="title" value="{{ old('title') }}">
                @error('title')
                    <small class="text-danger">{{ $message }}</small>
                @enderror
            </div>
            <div class="mb-3">
                <label for="exampleInputEmail1" class="form-label">Author</label>
                <input type="text" class="form-control" name="author" value="{{ old('author') }}">
                @error('author')
                    <small class="text-danger">{{ $message }}</small>
                @enderror
            </div>
            <div class="mb-3">
                <label for="exampleInputEmail1" class="form-label">Price</label>
                <input type="Price" class="form-control" name="price" min=0 value="{{ old('price') }}">
                @error('price')
                    <small class="text-danger">{{ $message }}</small>
                @enderror
            </div>
            <div class="mb-3">
                <label for="exampleInputEmail1" class="form-label">ISBN</label>
                <input type="text" class="form-control" name="isbn" value="{{ old('isbn') }}">
                @error('isbn')
                    <small class="text-danger">{{ $message }}</small>
                @enderror
            </div>
            <button type="submit" class="btn btn-primary">Submit</button>
        </form>


    @endsection