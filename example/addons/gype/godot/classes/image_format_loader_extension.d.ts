
import type { FileAccess } from '@godot/classes/file_access';
import type { Image } from '@godot/classes/image';
import type { ImageFormatLoader } from '@godot/classes/image_format_loader';


export declare class ImageFormatLoaderExtension extends ImageFormatLoader {


    public _get_recognized_extensions(): PackedStringArray;
    public _load_image(image: Image, fileaccess: FileAccess, flags: number, scale: number): number;
    public add_format_loader(): void;
    public remove_format_loader(): void;


}

