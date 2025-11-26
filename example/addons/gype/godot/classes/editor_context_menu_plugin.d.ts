
import type { PopupMenu } from '@godot/classes/popup_menu';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Shortcut } from '@godot/classes/shortcut';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class EditorContextMenuPlugin extends RefCounted {


    public _popup_menu(paths: PackedStringArray): void;
    public add_menu_shortcut(shortcut: Shortcut, callback: Callable | Function): void;
    public add_context_menu_item(name: GDString | StringName | string, callback: Callable | Function, icon: Texture2D = null): void;
    public add_context_menu_item_from_shortcut(name: GDString | StringName | string, shortcut: Shortcut, icon: Texture2D = null): void;
    public add_context_submenu_item(name: GDString | StringName | string, menu: PopupMenu, icon: Texture2D = null): void;


    public static readonly ContextMenuSlot: {
        CONTEXT_SLOT_SCENE_TREE: 0;
        CONTEXT_SLOT_FILESYSTEM: 1;
        CONTEXT_SLOT_SCRIPT_EDITOR: 2;
        CONTEXT_SLOT_FILESYSTEM_CREATE: 3;
        CONTEXT_SLOT_SCRIPT_EDITOR_CODE: 4;
        CONTEXT_SLOT_SCENE_TABS: 5;
        CONTEXT_SLOT_2D_EDITOR: 6;
    };
}

