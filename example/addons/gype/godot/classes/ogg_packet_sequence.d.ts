
import type { Resource } from '@godot/classes/resource';


export declare class OggPacketSequence extends Resource {

    
    /**     * The raw type is 'typedarray::PackedByteArray'     */
    public packet_data: Array<any>;    
    /**     * The raw type is 'PackedInt64Array'     */
    public granule_positions: PackedInt64Array;    
    /**     * The raw type is 'float'     */
    public sampling_rate: number;
    public set_packet_data(packetData: Array<any>): void;
    public get_packet_data(): Array<any>;
    public set_packet_granule_positions(granulePositions: PackedInt64Array): void;
    public get_packet_granule_positions(): PackedInt64Array;
    public set_sampling_rate(samplingRate: number): void;
    public get_sampling_rate(): number;
    public get_length(): number;


}

