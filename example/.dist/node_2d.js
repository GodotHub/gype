var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
import { Node2D } from "@godot/classes/node2d";
import { GodotClass } from "@godot/core/class_defined";
let node_2d = class node_2d extends Node2D {
    _enter_tree() {
    }
    _ready() {
    }
    _process(delta) {
    }
};
node_2d = __decorate([
    GodotClass
], node_2d);
export { node_2d };