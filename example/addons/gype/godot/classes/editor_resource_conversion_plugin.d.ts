
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Resource } from '@godot/classes/resource';


export declare class EditorResourceConversionPlugin extends RefCounted {


    public _converts_to(): GDString;
    public _handles(resource: Resource): boolean;
    public _convert(resource: Resource): Resource;


}

