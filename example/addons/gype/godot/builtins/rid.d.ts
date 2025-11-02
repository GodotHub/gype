

declare global {
    declare class RID {
        constructor();
        constructor(_from: RID);


        public is_valid(): boolean;
        public get_id(): number;

    }
}

export {};