
import type { AudioStreamOggVorbis } from '@godot/classes/audio_stream_ogg_vorbis';
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { ResourceImporter } from '@godot/classes/resource_importer';


export declare class ResourceImporterOggVorbis extends ResourceImporter {


    public static load_from_buffer(streamData: PackedByteArray): AudioStreamOggVorbis;
    public static load_from_file(path: GDString | StringName | string): AudioStreamOggVorbis;


}

