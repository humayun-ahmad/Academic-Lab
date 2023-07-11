@extends('layouts.main')
    @section('content')
        <h2>Books</h2>
        {{-- create a button t ocreate book --}}
        <a href="{{ route('books.create') }}" class="btn btn-primary mt-4">Create Book</a>
        <table class="table">
            <thead>
                <th>Id</th>
                <th>Title</th>
                <th>Author</th>
                <th>Price</th>
                <th>Isbn</th>
                <th>Action</th>
            </thead>
            <tbody>
                @foreach($books as $book)
                    <tr>
                        <td>{{ $book->id }}</td>
                        <td>{{ $book->title}}</td>
                        <td>{{$book->author}} </td>
                        <td>{{ $book->price}}</td>
                        <td>{{ $book->isbn}}</td>
                        <td>
                            <a href="{{ route('books.edit',['book'=>$book] ) }}" class="btn btn-secondary">Edit</a>
                            <form action="{{ route('books.destroy', ['book'=>$book]) }}" method="POST" class="d-inline">
                                @csrf
                                @method('DELETE')
                                <button type="submit" class="btn btn-danger">Delete</button>
                            </form>
                        </td>
                    </tr>
                @endforeach
            </tbody>
        </table>
        @endsection