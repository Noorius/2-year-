import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Product } from './products';

@Injectable({
  providedIn: 'root'
})
export class AmazonService {

  constructor(
    private http: HttpClient
  ) { }

  getItems(){
    return this.http.get<{
      url: string,
      name: string,
      price: number,
      description: string,
      image1: string,
      image2: string,
      image3: string,
      rating: number}[]>
    ('/assets/products.json');

  }
}
