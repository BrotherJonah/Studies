import { Component, OnInit } from '@angular/core';

import {Recipe} from '../recipe.model';

@Component({
  selector: 'app-recipe-list',
  templateUrl: './recipe-list.component.html',
  styleUrls: ['./recipe-list.component.css']
})
export class RecipeListComponent implements OnInit {
  recipes: Recipe[] = [
    new Recipe('A test recipe', 'simple test', 'https://cdn.sallysbakingaddiction.com/wp-content/uploads/2014/01/whole-wheat-margherita-pizza.jpg'),
    new Recipe('A test recipe', 'simple test', 'https://cdn.sallysbakingaddiction.com/wp-content/uploads/2014/01/whole-wheat-margherita-pizza.jpg')
  ];

  constructor() { }

  ngOnInit(): void {
  }

}
